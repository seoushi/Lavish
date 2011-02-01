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
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/timer.o \
	${OBJECTDIR}/_ext/1910445120/settings.o \
	${OBJECTDIR}/src/dataBuffer.o \
	${OBJECTDIR}/src/consoleLogger.o \
	${OBJECTDIR}/src/logger.o \
	${OBJECTDIR}/src/fileSystem.o \
	${OBJECTDIR}/src/fileStream.o


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
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/libcore.a

dist/Release/GNU-Linux-x86/libcore.a: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${RM} dist/Release/GNU-Linux-x86/libcore.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcore.a ${OBJECTFILES} 
	$(RANLIB) dist/Release/GNU-Linux-x86/libcore.a

${OBJECTDIR}/src/timer.o: src/timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/timer.o src/timer.cpp

${OBJECTDIR}/_ext/1910445120/settings.o: /home/sean/Projects/Lavish/core/src/settings.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1910445120
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1910445120/settings.o /home/sean/Projects/Lavish/core/src/settings.cpp

${OBJECTDIR}/src/dataBuffer.o: src/dataBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/dataBuffer.o src/dataBuffer.cpp

${OBJECTDIR}/src/consoleLogger.o: src/consoleLogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/consoleLogger.o src/consoleLogger.cpp

${OBJECTDIR}/src/logger.o: src/logger.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/logger.o src/logger.cpp

${OBJECTDIR}/src/fileSystem.o: src/fileSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/fileSystem.o src/fileSystem.cpp

${OBJECTDIR}/src/fileStream.o: src/fileStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Iexternal/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/fileStream.o src/fileStream.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/libcore.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
