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
# XXX	BUILDLINK_DEPMETHOD.mkfontscale?=	build

BUILDLINK_TREE+=	mkfontscale

.if !defined(MKFONTSCALE_BUILDLINK3_MK)
MKFONTSCALE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mkfontscale+=	mkfontscale>=1.1.2
BUILDLINK_PKGSRCDIR.mkfontscale?=	../../fonts/mkfontscale

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif	# MKFONTSCALE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mkfontscale
