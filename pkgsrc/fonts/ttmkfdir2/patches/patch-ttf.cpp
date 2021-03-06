$NetBSD$

--- ttf.cpp.orig	2002-11-07 05:30:04.000000000 +0000
+++ ttf.cpp
@@ -3,7 +3,8 @@
 #include <cctype>
 #include <cstring>
 
-#include "freetype/tttables.h"
+#include <ft2build.h>
+#include FT_TRUETYPE_TABLES_H
 #include "ttmkfdir.h"
 #include "ttf.h"
 #include "ttos2val.h"
@@ -137,7 +138,12 @@ Face::Face (const std::string &filename)
 	/*
 	 * find all the encodings that are based on this cmap.
 	 */
+#if defined(__SUNPRO_CC)
+	/* Error: Cannot use ... ::iterator ... to initialize ... ::const_iterator ... */
+	typedef Encodings_t::iterator MI;
+#else
 	typedef Encodings_t::const_iterator MI;
+#endif
 	std::pair<MI, MI> bounds = Encodings::instance()->equal_range (key);
 
 	/*
@@ -226,7 +232,7 @@ Face::FontFamilyName (void) const
 	for (i = 0; i < n; i++) {
 	    if ((fterror = FT_Get_Sfnt_Name (face, i, &NamePtr)) != FT_Err_Ok) {
                     std::cout << "Warning: Can't SFNT name : " << FileName << "(" << fterror << ")" << std::endl;
-	            return;
+	            return "unknown";
             };
             platform = NamePtr.platform_id;
             encoding = NamePtr.encoding_id;
@@ -522,7 +528,7 @@ Face::Weight (void) const
 {
     const char *result;
     
-    if (cmdline::instance()->option ("panose") && ((result = PanoseWeight ()) != 0)) {
+    if (bool(cmdline::instance()->option ("panose")) && ((result = PanoseWeight ()) != 0)) {
 	return result;
     } else if ((result = OS2Weight ()) != 0) {
 	return result;
@@ -603,7 +609,7 @@ Face::Width (void) const
 {
     const char *result;
     
-    if (cmdline::instance()->option ("panose") && ((result = PanoseWidth ()) != 0)) {
+    if (bool(cmdline::instance()->option ("panose")) && ((result = PanoseWidth ()) != 0)) {
 	return result;
     } else if ((result = OS2Width ()) != 0) {
 	return result;
