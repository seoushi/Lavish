#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/external/src/physfs_byteorder.o \
	${OBJECTDIR}/external/src/posix.o \
	${OBJECTDIR}/external/src/grp.o \
	${OBJECTDIR}/_ext/1910445120/settings.o \
	${OBJECTDIR}/external/src/wad.o \
	${OBJECTDIR}/external/src/unix.o \
	${OBJECTDIR}/external/src/physfs.o \
	${OBJECTDIR}/external/src/7zHeader.o \
	${OBJECTDIR}/external/src/hog.o \
	${OBJECTDIR}/external/src/BranchX86.o \
	${OBJECTDIR}/src/consoleLogger.o \
	${OBJECTDIR}/external/src/7zAlloc.o \
	${OBJECTDIR}/external/src/zip.o \
	${OBJECTDIR}/external/src/pocketpc.o \
	${OBJECTDIR}/external/src/physfs_unicode.o \
	${OBJECTDIR}/external/src/mvl.o \
	${OBJECTDIR}/external/src/7zBuffer.o \
	${OBJECTDIR}/external/src/7zIn.o \
	${OBJECTDIR}/src/logger.o \
	${OBJECTDIR}/external/src/7zItem.o \
	${OBJECTDIR}/external/src/7zDecode.o \
	${OBJECTDIR}/src/fileSystem.o \
	${OBJECTDIR}/external/src/windows.o \
	${OBJECTDIR}/external/src/os2.o \
	${OBJECTDIR}/external/src/lzma.o \
	${OBJECTDIR}/external/src/7zExtract.o \
	${OBJECTDIR}/external/src/BranchX86_2.o \
	${OBJECTDIR}/external/src/dir.o \
	${OBJECTDIR}/src/fileStream.o \
	${OBJECTDIR}/external/src/macosx.o \
	${OBJECTDIR}/external/src/7zMethodID.o \
	${OBJECTDIR}/external/src/qpak.o \
	${OBJECTDIR}/external/src/LzmaDecode.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x
CXXFLAGS=-std=c++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libcore.a

dist/Debug/GNU-Linux-x86/libcore.a: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${RM} dist/Debug/GNU-Linux-x86/libcore.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcore.a ${OBJECTFILES} 
	$(RANLIB) dist/Debug/GNU-Linux-x86/libcore.a

${OBJECTDIR}/external/src/physfs_byteorder.o: external/src/physfs_byteorder.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/physfs_byteorder.o external/src/physfs_byteorder.c

${OBJECTDIR}/external/src/posix.o: external/src/posix.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/posix.o external/src/posix.c

${OBJECTDIR}/external/src/grp.o: external/src/grp.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/grp.o external/src/grp.c

${OBJECTDIR}/_ext/1910445120/settings.o: /home/sean/Projects/Lavish/core/src/settings.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1910445120
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1910445120/settings.o /home/sean/Projects/Lavish/core/src/settings.cpp

${OBJECTDIR}/external/src/wad.o: external/src/wad.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/wad.o external/src/wad.c

${OBJECTDIR}/external/src/unix.o: external/src/unix.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/unix.o external/src/unix.c

${OBJECTDIR}/external/src/physfs.o: external/src/physfs.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/physfs.o external/src/physfs.c

${OBJECTDIR}/external/src/7zHeader.o: external/src/7zHeader.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/7zHeader.o external/src/7zHeader.c

${OBJECTDIR}/external/src/hog.o: external/src/hog.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/hog.o external/src/hog.c

${OBJECTDIR}/external/src/BranchX86.o: external/src/BranchX86.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/BranchX86.o external/src/BranchX86.c

${OBJECTDIR}/src/consoleLogger.o: src/consoleLogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/consoleLogger.o src/consoleLogger.cpp

${OBJECTDIR}/external/src/7zAlloc.o: external/src/7zAlloc.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/7zAlloc.o external/src/7zAlloc.c

${OBJECTDIR}/external/src/zip.o: external/src/zip.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/zip.o external/src/zip.c

${OBJECTDIR}/external/src/pocketpc.o: external/src/pocketpc.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/pocketpc.o external/src/pocketpc.c

${OBJECTDIR}/external/src/physfs_unicode.o: external/src/physfs_unicode.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/physfs_unicode.o external/src/physfs_unicode.c

${OBJECTDIR}/external/src/mvl.o: external/src/mvl.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/mvl.o external/src/mvl.c

${OBJECTDIR}/external/src/7zBuffer.o: external/src/7zBuffer.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/7zBuffer.o external/src/7zBuffer.c

${OBJECTDIR}/external/src/7zIn.o: external/src/7zIn.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/7zIn.o external/src/7zIn.c

${OBJECTDIR}/src/logger.o: src/logger.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/logger.o src/logger.cpp

${OBJECTDIR}/external/src/7zItem.o: external/src/7zItem.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/7zItem.o external/src/7zItem.c

${OBJECTDIR}/external/src/7zDecode.o: external/src/7zDecode.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/7zDecode.o external/src/7zDecode.c

${OBJECTDIR}/src/fileSystem.o: src/fileSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/fileSystem.o src/fileSystem.cpp

${OBJECTDIR}/external/src/windows.o: external/src/windows.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/windows.o external/src/windows.c

${OBJECTDIR}/external/src/os2.o: external/src/os2.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/os2.o external/src/os2.c

${OBJECTDIR}/external/src/lzma.o: external/src/lzma.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/lzma.o external/src/lzma.c

${OBJECTDIR}/external/src/7zExtract.o: external/src/7zExtract.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/7zExtract.o external/src/7zExtract.c

${OBJECTDIR}/external/src/BranchX86_2.o: external/src/BranchX86_2.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/BranchX86_2.o external/src/BranchX86_2.c

${OBJECTDIR}/external/src/dir.o: external/src/dir.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/dir.o external/src/dir.c

${OBJECTDIR}/src/fileStream.o: src/fileStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/fileStream.o src/fileStream.cpp

${OBJECTDIR}/external/src/macosx.o: external/src/macosx.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/macosx.o external/src/macosx.c

${OBJECTDIR}/external/src/7zMethodID.o: external/src/7zMethodID.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/7zMethodID.o external/src/7zMethodID.c

${OBJECTDIR}/external/src/qpak.o: external/src/qpak.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/qpak.o external/src/qpak.c

${OBJECTDIR}/external/src/LzmaDecode.o: external/src/LzmaDecode.c 
	${MKDIR} -p ${OBJECTDIR}/external/src
	${RM} $@.d
	$(COMPILE.c) -g -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/external/src/LzmaDecode.o external/src/LzmaDecode.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libcore.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
