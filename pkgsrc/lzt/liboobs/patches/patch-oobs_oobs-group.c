$NetBSD$

--- oobs/oobs-group.c.orig	2009-09-05 14:07:20.000000000 +0000
+++ oobs/oobs-group.c
@@ -18,6 +18,10 @@
  * Authors: Carlos Garnacho Parro  <carlosg@gnome.org>
  */
 
+#if defined(HAVE_CONFIG_H)
+#include <config.h>
+#endif
+
 #include <glib-object.h>
 #include "oobs-session.h"
 #include "oobs-group.h"
@@ -27,7 +31,11 @@
 #include "oobs-usersconfig.h"
 #include "oobs-defines.h"
 #include "utils.h"
+#ifdef HAVE_CRYPT_H
 #include <crypt.h>
+#else
+#include <unistd.h>
+#endif
 
 /**
  * SECTION:oobs-group
