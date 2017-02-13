# maximum parallelism
SUBDIR_ORDERED=

SUBDIR=	CLANG LLVM
.if defined(WANT_CLANG_LLVMGOLD)
SUBDIR+= LLVMgold_pic
.endif

.include <bsd.subdir.mk>
