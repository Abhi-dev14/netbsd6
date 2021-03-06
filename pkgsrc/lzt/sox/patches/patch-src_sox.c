$NetBSD$

--- src/sox.c.orig	2014-10-06 02:02:30.000000000 +0000
+++ src/sox.c
@@ -1321,7 +1321,9 @@ static void adjust_volume(int delta)
       vol2 = range_limit(vol1 + delta, 0, 100);
       AUDIO_INITINFO(&audio_info);
       audio_info.play.gain = (vol2 * AUDIO_MAX_GAIN + 50) / 100;
+#if !defined(__NetBSD__)
       audio_info.output_muted = 0;
+#endif
       lsx_debug("%04x %04x", vol1, vol2);
       if (vol1 != vol2 && ioctl(fd, AUDIO_SETINFO, &audio_info) < 0)
         vol2 = vol1;
