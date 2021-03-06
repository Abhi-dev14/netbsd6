$NetBSD$

--- daemon/fstype.c.orig	2007-07-30 20:06:57.000000000 +0000
+++ daemon/fstype.c
@@ -89,8 +89,10 @@ static int xatoi P_((char *cp));
 
 #ifdef FSTYPE_STATVFS		/* SVR4.  */
 #include <sys/statvfs.h>
+#ifndef __NetBSD__
 #include <sys/fstyp.h>
 #endif
+#endif
 
 #ifdef FSTYPE_STATFS		/* 4.4BSD.  */
 #include <sys/param.h>		/* NetBSD needs this.  */
@@ -352,8 +354,12 @@ filesystem_type_uncached (char *path, ch
 	fstype_internal_error (1, errno, "%s", path);
     }
   else
+#ifdef __NetBSD__
+    type = fss.f_fstypename;
+#else
     type = fss.f_basetype;
 #endif
+#endif
 
 #ifdef FSTYPE_STATFS		/* 4.4BSD.  */
   struct statfs fss;
