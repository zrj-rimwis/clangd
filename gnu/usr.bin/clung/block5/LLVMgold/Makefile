# clangb gold LTO plugin

PROG_CXX=	LLVMgold.so
NOMAN=
BINDIR=	/usr/libexec/clangb

VERSION_SCRIPT= ${.CURDIR}/LLVMgold.exports

SRCS=	gold-plugin.cpp

CFLAGS+=	-fpic #-DPIC
LDFLAGS+=	-shared -Wl,-Bsymbolic
LDFLAGS+=	-Wl,-O3 -Wl,--gc-sections
LDFLAGS+=	-Wl,--version-script=${VERSION_SCRIPT}

CFLAGS+=	-I${TOP_LLVM}/include

# LLVM libraries
STLIB+=	LLVMgold_pic

# For plugin-api.h
CFLAGS+=	-I${TOP_LLVM}/tools/gold

.for SL in ${STLIB}
LDADD+=	${.OBJDIR}/../../block4/${SL}/lib${SL}.a
DPADD+=	${.OBJDIR}/../../block4/${SL}/lib${SL}.a
.endfor

# host library linkage
LDADD+=	-lz -lm

LLVM_SRCDIRS+=	tools/gold

.include <bsd.prog.mk>
