$NetBSD$

--- toolkit/components/protobuf/src/google/protobuf/stubs/platform_macros.h.orig	2016-05-12 17:13:28.000000000 +0000
+++ toolkit/components/protobuf/src/google/protobuf/stubs/platform_macros.h
@@ -67,7 +67,7 @@
 #define GOOGLE_PROTOBUF_ARCH_32_BIT 1
 #elif defined(sparc)
 #define GOOGLE_PROTOBUF_ARCH_SPARC 1
-#ifdef SOLARIS_64BIT_ENABLED
+#if (defined(sun) && defined(SOLARIS_64BIT_ENABLED)) || __LP64__
 #define GOOGLE_PROTOBUF_ARCH_64_BIT 1
 #else
 #define GOOGLE_PROTOBUF_ARCH_32_BIT 1
