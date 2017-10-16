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
# XXX	BUILDLINK_DEPMETHOD.libXpm?=	build

BUILDLINK_TREE+=	libXpm

.if !defined(LIBXPM_BUILDLINK3_MK)
LIBXPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXpm+=	libXpm>=3.5.12
BUILDLINK_PKGSRCDIR.libXpm?=	../../x11/libXpm

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif	# LIBXPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXpm
