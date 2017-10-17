$NetBSD$

--- ttf.h.orig	2002-11-07 05:28:44.000000000 +0000
+++ ttf.h
@@ -3,16 +3,19 @@
 #define TTF_H__
 
 #include <string>
-#include "freetype/freetype.h"
-#include "freetype/tttables.h"
-#include "freetype/ftsnames.h"
-#include "freetype/ttnameid.h"
-#include "freetype/fterrors.h"
-#include "freetype/ftmodule.h"
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_TRUETYPE_TABLES_H
+#include FT_SFNT_NAMES_H
+#include FT_TRUETYPE_IDS_H
+#include FT_ERRORS_H
+#include FT_MODULE_H
 
 #include "util.h"
 #include "encoding.h"
 
+using namespace std;
+
 namespace ttf {
 
     class Face {
