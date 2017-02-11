WARNS?=	2
TOP_CLUNG=	${.CURDIR}/../../../../../contrib/clung
TOP_LLVM=	${TOP_CLUNG}/llvm
CFLAGS+=	-I${.OBJDIR} \
		-I${.OBJDIR}/../../block3 \
		-I${.CURDIR}/../../block1/pregenerated \
		-I${TOP_LLVM}/include

CFLAGS+=	-D__STDC_CONSTANT_MACROS \
		-D__STDC_FORMAT_MACROS \
		-D__STDC_LIMIT_MACROS

CXXFLAGS+=	-std=c++11 -fno-exceptions -fno-rtti

# -fstrict-aliasing is a no-no for llvm and clang
NO_STRICT_ALIASING=yes

.for _t in ${LLVM_SRCDIRS}
.PATH:		${TOP_LLVM}/${_t}
.endfor

.for _t in ${CLUNG_SRCDIRS}
.PATH:		${TOP_CLUNG}/${_t}
.endfor

.if defined(CLANG_INCLUDES)
.PATH:		${.OBJDIR}/../../block3/clang/Headers
.endif
