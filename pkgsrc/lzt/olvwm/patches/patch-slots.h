$NetBSD$

--- slots.h.orig	1998-01-13 21:00:57.000000000 +0000
+++ slots.h
@@ -45,12 +45,12 @@ extern struct _iconSlot *SlotAlloc();	/*
 	 * parameter; False should be passed otherwise.
 	 */
 
-extern Bool SlotFree();		/* WinIcon * */
+void SlotFree(WinIconFrame *winicon);
  	/* An icon is going away, so its references to slots should also go
 	 * away. 
 	 */
 
-extern Bool SlotSetLocations();	/* Display *dpy */
+void SlotSetLocations(Display *dpy, IconGrid *iconGrid);
 	/* sets the order in which slots are allocated for icons which are
 	 * not explicitly positioned.  The new order is obtained from the
 	 * global resource vector.
