# maximum parallelism
SUBDIR_ORDERED=

SUBDIR=	clangb headers
.if defined(WANT_CLANG_LLVMGOLD)
SUBDIR+= LLVMgold
.endif

.include <bsd.subdir.mk>
