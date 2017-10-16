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
# XXX	BUILDLINK_DEPMETHOD.libmatemixer?=	build

BUILDLINK_TREE+=	libmatemixer

.if !defined(LIBMATEMIXER_BUILDLINK3_MK)
LIBMATEMIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatemixer+=	libmatemixer>=1.18.0nb1
BUILDLINK_PKGSRCDIR.libmatemixer?=	../../audio/libmatemixer

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBMATEMIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatemixer
