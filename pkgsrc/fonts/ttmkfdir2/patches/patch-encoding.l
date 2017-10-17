$NetBSD$

--- encoding.l.orig	2002-11-07 05:28:44.000000000 +0000
+++ encoding.l
@@ -148,7 +148,7 @@ STARTENCODING{WHITESPACES}{STRING} {
 
 <INSIDE_MAP_BLOCK>ENDMAPPING {
     cur_enc->AddMapping (cur_map);
-    dest.insert (std::make_pair(cur_map->cmapkey(), cur_enc));;
+    dest.insert (Encodings_t::value_type(cur_map->cmapkey(), cur_enc));
     BEGIN(INSIDE_ENC_BLOCK);
 }
 
