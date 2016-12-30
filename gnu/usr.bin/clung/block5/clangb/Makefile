# clangb driver

PROG_CXX=	clangb

BINDIR?=	/usr/libexec/clangb

SRCS=	driver.cpp \
	cc1_main.cpp \
	cc1as_main.cpp

LINKS=	${BINDIR}/clangb ${BINDIR}/cc \
	${BINDIR}/clangb ${BINDIR}/CC \
	${BINDIR}/clangb ${BINDIR}/cpp \
	${BINDIR}/clangb ${BINDIR}/c++ \
	${BINDIR}/clangb ${BINDIR}/clangb++

# clang-specific libraries
STLIB=	CLANG

# LLVM libraries
STLIB+=	LLVM

CFLAGS+=	-I${TOP_CLUNG}/include

.for SL in ${STLIB}
LDADD+=	${.OBJDIR}/../../block4/${SL}/lib${SL}.a
DPADD+=	${.OBJDIR}/../../block4/${SL}/lib${SL}.a
.endfor

# host library linkage
LDADD+=	-lpthread -lz -lm

CLUNG_SRCDIRS+=	tools/driver

.include <bsd.prog.mk>
