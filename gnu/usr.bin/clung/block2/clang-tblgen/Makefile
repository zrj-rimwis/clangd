PROG_CXX=	clang-tblgen

.if ${WORLD_VERSION} <= 400711
# XXX avoid -std= options, also any of -m*
NXCXXFLAGS=	${CFLAGS:N-flto:N-std=*:N-m*}
.endif

CXXFLAGS+=	${CXXFLAGS_CLANG}
NXCXXFLAGS+=	${CXXFLAGS_CLANG}

beforedepend: clang-tblgen.nx

install:
	# don't install the table generators

.include "${.CURDIR}/Makefile.sources"
.include <bsd.hostprog.mk>
