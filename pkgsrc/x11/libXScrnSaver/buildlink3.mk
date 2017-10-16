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
# XXX	BUILDLINK_DEPMETHOD.libXScrnSaver?=	build

BUILDLINK_TREE+=	libXScrnSaver

.if !defined(LIBXSCRNSAVER_BUILDLINK3_MK)
LIBXSCRNSAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXScrnSaver+=	libXScrnSaver>=1.2.2
BUILDLINK_PKGSRCDIR.libXScrnSaver?=	../../x11/libXScrnSaver

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.endif	# LIBXSCRNSAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXScrnSaver
