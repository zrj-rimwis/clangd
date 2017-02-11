LIB=	CLANG

.include "${.CURDIR}/Makefile.sources"
CFLAGS+= ${CFLAGS_CLANG}
CFLAGS+= -DDF_CLANG_HEADERS=\"${USRDATA_PREFIX}/usr/libdata/clangb\"

# XXX these are very strange when clang compiles itself, for now allow to emit
.if ${CCVER:Mclang*}
CXXFLAGS+= -Wno-error=unused-private-field
.endif

.include <bsd.lib.mk>
