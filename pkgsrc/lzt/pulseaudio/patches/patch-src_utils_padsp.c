$NetBSD$

--- src/utils/padsp.c.orig	2016-09-05 16:00:03.000000000 +0000
+++ src/utils/padsp.c
@@ -48,6 +48,10 @@
 #include <linux/sockios.h>
 #endif
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
 #include <pulse/pulseaudio.h>
 #include <pulse/gccmacro.h>
 #include <pulsecore/llist.h>
@@ -113,7 +117,11 @@ static pthread_mutex_t func_mutex = PTHR
 
 static PA_LLIST_HEAD(fd_info, fd_infos) = NULL;
 
+#ifdef __NetBSD__
+static int (*_ioctl)(int, u_long, void *) = NULL;
+#else
 static int (*_ioctl)(int, int, void*) = NULL;
+#endif
 static int (*_close)(int) = NULL;
 static int (*_open)(const char *, int, mode_t) = NULL;
 static int (*___open_2)(const char *, int) = NULL;
@@ -141,6 +149,15 @@ static inline fnptr dlsym_fn(void *handl
     return (fnptr) (long) dlsym(handle, symbol);
 }
 
+#ifdef __NetBSD__
+#define LOAD_IOCTL_FUNC() \
+do { \
+    pthread_mutex_lock(&func_mutex); \
+    if (!_ioctl)  \
+       _ioctl = (int (*)(int, u_long, void*)) dlsym_fn(RTLD_NEXT, "ioctl"); \
+    pthread_mutex_unlock(&func_mutex); \
+} while(0)
+#else
 #define LOAD_IOCTL_FUNC() \
 do { \
     pthread_mutex_lock(&func_mutex); \
@@ -148,6 +165,7 @@ do { \
         _ioctl = (int (*)(int, int, void*)) dlsym_fn(RTLD_NEXT, "ioctl"); \
     pthread_mutex_unlock(&func_mutex); \
 } while(0)
+#endif
 
 #define LOAD_OPEN_FUNC() \
 do { \
@@ -197,11 +215,21 @@ do { \
     pthread_mutex_unlock(&func_mutex); \
 } while(0)
 
+
+#ifdef __NetBSD__
+#if (__NetBSD_Version__ < 600000000)
+#define STAT_FUNC "__stat30"
+#else
+#define STAT_FUNC "__stat50"
+#endif
+#else
+#define STAT_FUNC "stat"
+#endif
 #define LOAD_STAT_FUNC() \
 do { \
     pthread_mutex_lock(&func_mutex); \
     if (!_stat) \
-        _stat = (int (*)(const char *, struct stat *)) dlsym_fn(RTLD_NEXT, "stat"); \
+        _stat = (int (*)(const char *, struct stat *)) dlsym_fn(RTLD_NEXT, STAT_FUNC); \
     pthread_mutex_unlock(&func_mutex); \
 } while(0)
 
@@ -2384,21 +2412,33 @@ fail:
     return ret;
 }
 
+/* NetBSD < 6 and 6.99.0 - 6.99.6 used a different ioctl() definition */
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 600000000 ||  \
+    (__NetBSD_Version__ > 699000000 && __NetBSD_Version__ < 699000700) )
+# define OLD_NETBSD_IOCTL_CALL
+#endif
+
 #ifdef sun
 int ioctl(int fd, int request, ...) {
+#elif defined(OLD_NETBSD_IOCTL_CALL)
+int ioctl(int fd, u_long request, void *_argp) {
 #else
 int ioctl(int fd, unsigned long request, ...) {
 #endif
     fd_info *i;
+#if !defined(OLD_NETBSD_IOCTL_CALL)
     va_list args;
+#endif
     void *argp;
     int r, _errno = 0;
 
     debug(DEBUG_LEVEL_VERBOSE, __FILE__": ioctl()\n");
 
+#if defined(OLD_NETBSD_IOCTL_CALL)
     va_start(args, request);
     argp = va_arg(args, void *);
     va_end(args);
+#endif
 
     if (!function_enter()) {
         LOAD_IOCTL_FUNC();
