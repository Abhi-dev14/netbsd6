$NetBSD$

--- plugins/coherence/upnp_coherence/UpnpSource.py.orig	2010-03-25 00:10:11.000000000 +0000
+++ plugins/coherence/upnp_coherence/UpnpSource.py
@@ -132,7 +132,7 @@ class UpnpSource(rb.BrowserSource,log.Lo
 
                     if duration is not None:
                         h,m,s = duration.split(':')
-                        seconds = int(h)*3600 + int(m)*60 + int(s)
+                        seconds = int(h)*3600 + int(m)*60 + int(round(float(s)))
                         self.info("%r %r:%r:%r %r", duration, h, m , s, seconds)
                         self.__db.set(entry, rhythmdb.PROP_DURATION, seconds)
 