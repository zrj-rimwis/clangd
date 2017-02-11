LIB=	LLVMtblgen

.if ${WORLD_VERSION} <= 400711
# XXX avoid -std= options, also any of -m*
NXCXXFLAGS=	${CFLAGS:N-flto:N-std=*:N-m*}
.endif

beforedepend: libLLVMtblgen.na

.include "${.CURDIR}/Makefile.sources"
.include <bsd.hostlib.mk>
