# $NetBSD: Makefile,v 1.28 2017/09/04 18:55:08 wiz Exp $
#

DISTNAME=	scim-unikey-0.3.1
PKGREVISION=	24
CATEGORIES=	inputmethod
MASTER_SITES=	http://scim-unikey.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/scim-unikey/
COMMENT=	Vietnamese Input Method Engine for SCIM using Unikey IME
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config msgfmt

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
