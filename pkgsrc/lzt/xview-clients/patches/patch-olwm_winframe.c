$NetBSD$

--- olwm/winframe.c.orig	1993-06-29 05:12:03.000000000 +0000
+++ olwm/winframe.c
@@ -1,4 +1,3 @@
-#ident	"@(#)winframe.c	26.77	93/06/28 SMI"
 
 /*
  *      (c) Copyright 1989 Sun Microsystems, Inc.
@@ -72,6 +71,7 @@ void FrameUpdateShape();
 static void setIMStatusText();
 #endif
 static void updateResizePositions();
+static int headerHeight(Client *cli, Graphics_info *gis);
 
 /***************************************************************************
 * sizing and decoration positioning functions
