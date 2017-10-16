# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.17.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.renderproto?=	build

BUILDLINK_TREE+=	renderproto

.if !defined(RENDERPROTO_BUILDLINK3_MK)
RENDERPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.11.1
BUILDLINK_PKGSRCDIR.renderproto?=	../../x11/renderproto
.endif	# RENDERPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-renderproto
