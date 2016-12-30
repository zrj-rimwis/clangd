INTERNALLIB=	yes
TOP_CLUNG=	${.CURDIR}/../../../../../contrib/clung
TOP_LLVM=	${TOP_CLUNG}/llvm
CFLAGS+=	-I${.OBJDIR} \
		-I${TOP_LLVM}/include \
		-I${.CURDIR}/../../block1/pregenerated

CFLAGS+=	-D__STDC_CONSTANT_MACROS \
		-D__STDC_FORMAT_MACROS \
		-D__STDC_LIMIT_MACROS

CXXFLAGS+=	-std=c++11 -fno-exceptions -fno-rtti

.for _t in ${LLVM_SRCDIRS}
.PATH:		${TOP_LLVM}/${_t}
.endfor
