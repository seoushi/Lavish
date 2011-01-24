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
	${OBJECTDIR}/src/Model.o \
	${OBJECTDIR}/src/StateManager.o \
	${OBJECTDIR}/src/Keyboard.o \
	${OBJECTDIR}/src/ShaderSet.o \
	${OBJECTDIR}/src/Rectangle.o \
	${OBJECTDIR}/src/Timer.o \
	${OBJECTDIR}/src/VertexFormats.o \
	${OBJECTDIR}/src/Font.o \
	${OBJECTDIR}/src/Resource.o \
	${OBJECTDIR}/src/Mouse.o \
	${OBJECTDIR}/src/EventListener.o \
	${OBJECTDIR}/src/Sprite.o \
	${OBJECTDIR}/src/Shader.o \
	${OBJECTDIR}/src/Exception.o \
	${OBJECTDIR}/src/DataBuffer.o \
	${OBJECTDIR}/src/Texture.o \
	${OBJECTDIR}/src/Display.o \
	${OBJECTDIR}/src/Matrix.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/liblavish.a

dist/Debug/GNU-Linux-x86/liblavish.a: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${RM} dist/Debug/GNU-Linux-x86/liblavish.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblavish.a ${OBJECTFILES} 
	$(RANLIB) dist/Debug/GNU-Linux-x86/liblavish.a

${OBJECTDIR}/src/Model.o: src/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Model.o src/Model.cpp

${OBJECTDIR}/src/StateManager.o: src/StateManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/StateManager.o src/StateManager.cpp

${OBJECTDIR}/src/Keyboard.o: src/Keyboard.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Keyboard.o src/Keyboard.cpp

${OBJECTDIR}/src/ShaderSet.o: src/ShaderSet.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ShaderSet.o src/ShaderSet.cpp

${OBJECTDIR}/src/Rectangle.o: src/Rectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Rectangle.o src/Rectangle.cpp

${OBJECTDIR}/src/Timer.o: src/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Timer.o src/Timer.cpp

${OBJECTDIR}/src/VertexFormats.o: src/VertexFormats.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VertexFormats.o src/VertexFormats.cpp

${OBJECTDIR}/src/Font.o: src/Font.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Font.o src/Font.cpp

${OBJECTDIR}/src/Resource.o: src/Resource.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Resource.o src/Resource.cpp

${OBJECTDIR}/src/Mouse.o: src/Mouse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Mouse.o src/Mouse.cpp

${OBJECTDIR}/src/EventListener.o: src/EventListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/EventListener.o src/EventListener.cpp

${OBJECTDIR}/src/Sprite.o: src/Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sprite.o src/Sprite.cpp

${OBJECTDIR}/src/Shader.o: src/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Shader.o src/Shader.cpp

${OBJECTDIR}/src/Exception.o: src/Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Exception.o src/Exception.cpp

${OBJECTDIR}/src/DataBuffer.o: src/DataBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/DataBuffer.o src/DataBuffer.cpp

${OBJECTDIR}/src/Texture.o: src/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Texture.o src/Texture.cpp

${OBJECTDIR}/src/Display.o: src/Display.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Display.o src/Display.cpp

${OBJECTDIR}/src/Matrix.o: src/Matrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Matrix.o src/Matrix.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/liblavish.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
