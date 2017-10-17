$NetBSD$

--- encoding.h.orig	2002-11-07 05:28:44.000000000 +0000
+++ encoding.h
@@ -6,7 +6,8 @@
 #include <map>
 #include <string>
 
-#include "freetype/freetype.h"
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include "util.h"
 
