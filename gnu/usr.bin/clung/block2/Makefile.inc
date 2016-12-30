TOP_CLUNG=	${.CURDIR}/../../../../../contrib/clung
TOP_LLVM=	${TOP_CLUNG}/llvm
CFLAGS+=	-I${.OBJDIR} \
		-I${TOP_LLVM}/include \
		-I${.CURDIR}/../../block1/pregenerated

CFLAGS+=	-D__STDC_CONSTANT_MACROS \
		-D__STDC_FORMAT_MACROS \
		-D__STDC_LIMIT_MACROS

CXXFLAGS+=	-std=c++11 -fno-exceptions -fno-rtti

LLVM_LIBS=	${.OBJDIR}/../../block1/LLVMtblgen/libLLVMtblgen.a

LDADD=		-lpthread -lz -lm ${LLVM_LIBS}

NOMAN=		yes

.for _t in ${LLVM_SRCDIRS}
.PATH:		${TOP_LLVM}/${_t}
.endfor

.for _t in ${CLUNG_SRCDIRS}
.PATH:		${TOP_CLUNG}/${_t}
.endfor

install:
	# don't install the table generators
