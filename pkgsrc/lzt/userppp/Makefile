# $NetBSD: Makefile,v 1.25 2012/10/23 17:19:16 asau Exp $

DISTNAME=		ppp-001107.src
PKGNAME=		userppp-001107
PKGREVISION=		3
CATEGORIES=		lzt
MASTER_SITES=		http://www.NetBSD.org/~ad/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.awfulhak.org/~brian/
COMMENT=		User-PPP package as found in FreeBSD and OpenBSD

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}
MANCOMPRESSED_IF_MANZ=	YES

PKG_SYSCONFSUBDIR=	ppp

CFLAGS+=		-fno-strict-aliasing
# fix build on -current for wrong is* arguments (char instead of unsigned char)
BUILDLINK_TRANSFORM+=	rm:-Werror

#SUBST_CLASSES+=		cfgdir
#SUBST_STAGE.cfgdir=	do-configure
#SUBST_FILES.cfgdir=	ppp/ppp.8 pppctl/pppctl.8
#SUBST_SED.cfgdir= 	-e "s,/etc/ppp,${PKG_SYSCONFDIR},"
#SUBST_SED.cfgdir+=	-e "s,/usr/share,${PREFIX}/share,"

.include "../../mk/bsd.prefs.mk"

SPECIAL_PERMS+=	sbin/ppp ${REAL_ROOT_USER} ${USERPPP_GROUP} 04554

USERPPP_GROUP?=	network
MAKE_ENV+=	USERPPP_GROUP=${USERPPP_GROUP:Q} BINOWN=${ROOT_USER}

PKG_GROUPS=	${USERPPP_GROUP}

PKG_GROUPS_VARS+=	USERPPP_GROUP
BUILD_DEFS+=		USERPPP_GROUP

USE_BSD_MAKEFILE=	yes

EGDIR=			${LOCALBASE}/share/examples/ppp

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin
INSTALLATION_DIRS+=	share/examples/ppp
INSTALLATION_DIRS+=	etc/ppp

OWN_DIRS=		${PKG_SYSCONFDIR}		

.for R in adsl.conf modem.conf ppp.3g ppp.conf ppptun.conf ppp.linkup
CONF_FILES+=		${EGDIR}/${R} ${PKG_SYSCONFDIR}/${R}
.endfor

CONF_FILES+=		${EGDIR}/gateways /etc/gateways

.for R in ppptun fixpf parseiface
CONF_FILES_PERMS+=	${EGDIR}/${R} ${PKG_SYSCONFDIR}/${R} \
			${REAL_ROOT_USER} network 0755
.endfor

post-install:
	cd ${FILESDIR};find share | \
		sed -e '/CVS/d' | \
		cpio -pdvm ${DESTDIR}${LOCALBASE}

.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit

dorsync:
	cd ..;sh dorsyncpackages userppp
