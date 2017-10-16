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
# XXX	BUILDLINK_DEPMETHOD.libXaw?=	build

BUILDLINK_TREE+=	libXaw

.if !defined(LIBXAW_BUILDLINK3_MK)
LIBXAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXaw+=	libXaw>=1.0.13
BUILDLINK_PKGSRCDIR.libXaw?=	../../x11/libXaw

BUILDLINK_TRANSFORM+=   l:Xaw:Xaw7

XAWLDFLAGS!=	pkg-config --libs xaw7
LDFLAGS+=	${XAWLDFLAGS}

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif	# LIBXAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXaw
