$NetBSD$

--- st.h.orig	1998-01-13 21:00:58.000000000 +0000
+++ st.h
@@ -40,7 +40,8 @@ struct st_table {
 
 enum st_retval {ST_CONTINUE, ST_STOP, ST_DELETE};
 
-int st_delete(), st_insert(), st_foreach(), st_free_table();
+void st_foreach(st_table *table, enum st_retval (*func)(), char *arg);
+int st_delete(), st_insert(), st_free_table();
 int st_lookup(), st_find_or_add(), st_add_direct();
 st_table *st_init_table(), *st_init_table_with_params();
 
