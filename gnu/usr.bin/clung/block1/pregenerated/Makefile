# Commonly used generation targets

DEFS=	Targets/LLVM_TARGET \
	AsmPrinters/LLVM_ASM_PRINTER \
	Disassemblers/LLVM_DISASSEMBLER \
	AsmParsers/LLVM_ASM_PARSER

all: #dummy
	@echo available: regen-def regen-version regen-DataTypes move-configs

regen-version: clang/Basic/Version.inc

clang/Basic/Version.inc:
	mkdir -p ${.TARGET:H}
	@echo '#define CLANG_VERSION 3.9.1' > ${.TARGET}
	@echo '#define CLANG_VERSION_MAJOR 3' >> ${.TARGET}
	@echo '#define CLANG_VERSION_MINOR 9' >> ${.TARGET}
	@echo '#define CLANG_VERSION_PATCHLEVEL 1' >> ${.TARGET}
	@echo '#define CLANG_VENDOR "DragonFly "' >> ${.TARGET}

regen-DataTypes: llvm/Support/DataTypes.h

llvm/Support/DataTypes.h: DataTypes.h.cmake
	mkdir -p ${.TARGET:H}
	sed -e 's|#cmakedefine|#define|' \
		-e 's|$${HAVE_INTTYPES_H}|1|' \
		-e 's|$${HAVE_STDINT_H}|1|' \
		-e 's|$${HAVE_UINT64_T}|1|' \
		-e 's|$${HAVE_U_INT64_T}|1|' ${.ALLSRC} > ${.TARGET}

move-configs: llvm/Config/config.h llvm/Config/llvm-config.h clang/Config/config.h

llvm/Config/config.h: config.h
	mkdir -p ${.TARGET:H}
	mv -f ${.ALLSRC} ${.TARGET}

llvm/Config/llvm-config.h: llvm-config.h
	mkdir -p ${.TARGET:H}
	mv -f ${.ALLSRC} ${.TARGET}

clang/Config/config.h: config.h.clang
	mkdir -p ${.TARGET:H}
	mv -f ${.ALLSRC} ${.TARGET}

.for D in ${DEFS}
regen-def: llvm/Config/${D:H}.def

llvm/Config/${D:H}.def:
	mkdir -p ${.TARGET:H}
	@echo "#ifndef ${D:T}" > ${.TARGET}
	@echo "#  error Please define the macro ${D:T}(TargetName)" >> ${.TARGET}
	@echo "#endif" >> ${.TARGET}
	@echo >> ${.TARGET}
	@echo "${D:T}(X86)" >> ${.TARGET}
.if defined(CLANG_EXTRA_TARGETS)
.   if ${CLANG_EXTRA_TARGETS:MAArch64}
	@echo "${D:T}(AArch64)" >> ${.TARGET}
.   endif
.   if ${CLANG_EXTRA_TARGETS:MAMDGPU}
.      if "${D:H}" != "Disassemblers"
	@echo "${D:T}(AMDGPU)" >> ${.TARGET}
.      endif
.   endif
.   if ${CLANG_EXTRA_TARGETS:MARM}
	@echo "${D:T}(ARM)" >> ${.TARGET}
.   endif
.   if ${CLANG_EXTRA_TARGETS:MMips}
	@echo "${D:T}(Mips)" >> ${.TARGET}
.   endif
.   if ${CLANG_EXTRA_TARGETS:MPowerPC}
	@echo "${D:T}(PowerPC)" >> ${.TARGET}
.   endif
.endif
	@echo >> ${.TARGET}
	@echo "#undef ${D:T}" >> ${.TARGET}
	@echo "${D:H}.def created."
.endfor
