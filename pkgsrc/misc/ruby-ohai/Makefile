# $NetBSD: Makefile,v 1.20 2017/09/10 14:43:41 taca Exp $

DISTNAME=	ohai-13.3.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/ohai
COMMENT=	Ohai profiles your system and emits JSON
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-systemu>=2.6.4<2.7:../../misc/ruby-systemu
DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.9<2:../../devel/ruby-ffi
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-yajl>=2.2<3:../../devel/ruby-ffi-yajl
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-cli>=1.5.0:../../devel/ruby-mixlib-cli
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-config>=2.1.0:../../devel/ruby-mixlib-config
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=1.6.0<2.0:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=2.0<3:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.1<4:../../textproc/ruby-plist
DEPENDS+=	${RUBY_PKGPREFIX}-ipaddress>=0.8.0:../../net/ruby-ipaddress
DEPENDS+=	${RUBY_PKGPREFIX}-wmi-lite>=1.0<2:../../devel/ruby-wmi-lite
DEPENDS+=	${RUBY_PKGPREFIX}-chef-config<14:../../sysutils/ruby-chef-config

RUBY_VERSIONS_ACCEPTED=	23 24

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
