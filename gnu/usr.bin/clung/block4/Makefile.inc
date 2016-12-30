INTERNALLIB=	yes
TOP_CLUNG=	${.CURDIR}/../../../../../contrib/clung
TOP_LLVM=	${TOP_CLUNG}/llvm
CFLAGS+=	-I${.OBJDIR} \
		-I${TOP_LLVM}/include \
		-I${.OBJDIR}/../../block3 \
		-I${.CURDIR}/../../block1/pregenerated \
		-I${.OBJDIR}/../../block3/generated

CFLAGS+=	-D__STDC_CONSTANT_MACROS \
		-D__STDC_FORMAT_MACROS \
		-D__STDC_LIMIT_MACROS

CXXFLAGS+=	-std=c++11 -fno-exceptions -fno-rtti

#CFLAGS_X86=	-I${TOP_LLVM}/lib/Target/X86 \
		-I${.OBJDIR}/../../block3/lib/Target/X86
CFLAGS_CLANG=	-I${TOP_CLUNG}/include

.for _t in ${LLVM_SRCDIRS}
.PATH:		${TOP_LLVM}/${_t}
.endfor

.for _t in ${CLUNG_SRCDIRS}
.PATH:		${TOP_CLUNG}/${_t}
.endfor
