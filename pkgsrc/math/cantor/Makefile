# $NetBSD: Makefile,v 1.34 2017/08/24 20:03:28 adam Exp $

DISTNAME=	cantor-${_KDE_VERSION}
PKGREVISION=	7
CATEGORIES=	math
COMMENT=	KDE frontend to mathematical software

.include "../../meta-pkgs/kde4/Makefile.kde4"

CMAKE_ARGS+= -DWITH_R=OFF
CMAKE_ARGS+= -DWITH_LuaJIT=OFF

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/python/application.mk"
.include "../../math/analitza/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
