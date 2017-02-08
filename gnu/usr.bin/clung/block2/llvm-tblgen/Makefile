PROG_CXX=	llvm-tblgen

# XXX avoid -std= options, also any of -m*
NXCXXFLAGS=	${CFLAGS:N-std=*:N-m*}

beforedepend: llvm-tblgen.nx

install:
	# don't install the table generators

.include "${.CURDIR}/Makefile.sources"
.include <bsd.hostprog.mk>
