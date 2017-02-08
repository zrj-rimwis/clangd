LIB=	LLVMtblgen

# XXX avoid -std= options, also any of -m*
NXCXXFLAGS=	${CFLAGS:N-std=*:N-m*}

beforedepend: libLLVMtblgen.na

.include "${.CURDIR}/Makefile.sources"
.include <bsd.hostlib.mk>
