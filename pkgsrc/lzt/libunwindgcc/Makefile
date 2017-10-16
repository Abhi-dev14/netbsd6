# $NetBSD$

DISTNAME=	libunwind-1.2
CATEGORIES=	lzt
MASTER_SITES=	http://download.savannah.nongnu.org/releases/libunwind/

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://download.savannah.nongnu.org/releases/libunwind/
COMMENT=	libunwind from the savannah project

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/coredump/libunwind-coredump.pc.in
PKGCONFIG_OVERRIDE+=	src/ptrace/libunwind-ptrace.pc.in
PKGCONFIG_OVERRIDE+=	src/setjmp/libunwind-setjmp.pc.in
PKGCONFIG_OVERRIDE+=	src/unwind/libunwind.pc.in
PKGCONFIG_OVERRIDE+=	src/libunwind-generic.pc.in

CONFIGURE_ARGS+=	--disable-coredump
CONFIGURE_ARGS+=	--disable-ptrace
CONFIGURE_ARGS+=	--build=x86

.include "../../mk/bsd.pkg.mk"
