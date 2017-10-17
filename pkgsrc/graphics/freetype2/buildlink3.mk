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
# XXX	BUILDLINK_DEPMETHOD.freetype2?=	build

BUILDLINK_TREE+=	freetype2

.if !defined(FREETYPE2_BUILDLINK3_MK)
FREETYPE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.8
BUILDLINK_PKGSRCDIR.freetype2?=	../../graphics/freetype2
TCFLAGS!=	/usr/pkg/bin/pkg-config --cflags freetype2
TLDFLAGS!=	/usr/pkg/bin/pkg-config --libs freetype2

CFLAGS+=	${TCFLAGS}
LDFLAGS+=	${TLDFLAGS}

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# FREETYPE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetype2
