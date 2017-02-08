TOP_CLUNG=	${.CURDIR}/../../../../../contrib/clung
TOP_LLVM=	${TOP_CLUNG}/llvm
TBL_INCS+=	-I${.OBJDIR} \
		-I${TOP_LLVM}/include \
		-I${.CURDIR}/../../block1/pregenerated

CFLAGS+=	${TBL_INCS}

CFLAGS+=	-D__STDC_CONSTANT_MACROS \
		-D__STDC_FORMAT_MACROS \
		-D__STDC_LIMIT_MACROS

NXCXXFLAGS+=	-std=c++11 -fno-exceptions -fno-rtti
CXXFLAGS+=	-std=c++11 -fno-exceptions -fno-rtti

CXXFLAGS_CLANG=	-I${TOP_CLUNG}/include

LLVM_LIBS=	${.OBJDIR}/../../block1/LLVMtblgen/libLLVMtblgen.na

LDADD=		${LLVM_LIBS} -lz -lm

${PROG_CXX}.nx: ${LLVM_LIBS}

NOMAN=

.for _t in ${LLVM_SRCDIRS}
.PATH:		${TOP_LLVM}/${_t}
.endfor

.for _t in ${CLUNG_SRCDIRS}
.PATH:		${TOP_CLUNG}/${_t}
.endfor

install:
	# don't install the table generators

# XXX helper for lack of .cxx.no in sys.mk
.cpp.no:
	${NXCXX} ${_${.IMPSRC:T}_FLAGS} ${NXCXXFLAGS} -c ${.IMPSRC} -o ${.TARGET}
