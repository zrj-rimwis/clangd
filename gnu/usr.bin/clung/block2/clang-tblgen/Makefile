PROG_CXX=	clang-tblgen

# XXX avoid -std= options, also any of -m*
NXCXXFLAGS=	${CFLAGS:N-std=*:N-m*}
CXXFLAGS+=	${CXXFLAGS_CLANG}
NXCXXFLAGS+=	${CXXFLAGS_CLANG}

beforedepend: clang-tblgen.nx

install:
	# don't install the table generators

.include "${.CURDIR}/Makefile.sources"
.include <bsd.hostprog.mk>
