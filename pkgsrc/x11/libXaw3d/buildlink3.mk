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
# XXX	BUILDLINK_DEPMETHOD.libXaw3d?=	build

BUILDLINK_TREE+=	libXaw3d

.if !defined(LIBXAW3D_BUILDLINK3_MK)
LIBXAW3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXaw3d+=	libXaw3d>=1.6.2
BUILDLINK_PKGSRCDIR.libXaw3d?=	../../x11/libXaw3d

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.endif	# LIBXAW3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXaw3d
