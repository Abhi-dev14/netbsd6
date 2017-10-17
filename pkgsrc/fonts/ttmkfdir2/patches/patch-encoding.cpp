$NetBSD$

--- encoding.cpp.orig	2002-11-07 05:28:44.000000000 +0000
+++ encoding.cpp
@@ -2,7 +2,7 @@
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
-#include "freetype/freetype.h"
+#include <ft2build.h>
 
 #include "ttmkfdir.h"
 #include "encoding.h"
@@ -101,5 +101,5 @@ Encoding::Encoding (Encodings_t *dest, B
 	(*m)[i] = b->mapdata.mappingtable[i];
 
     AddMapping (m);
-    dest->insert (std::make_pair(m->cmapkey(), this));;
+    dest->insert (Encodings_t::value_type(m->cmapkey(), this));
 }
