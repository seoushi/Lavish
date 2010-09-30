CXX = g++

CFLAGS := -I/usr/include/SDL -I../../include -O2 -pipe -Wall -ansi -fPIC
LDFLAGS := -lGL -lGLU -lGLEW -lSDL_image `sdl-config --cflags --libs` -shared

LIBRARY = liblavish.so

SRC=\
  ../../src/common/color.cpp\
  ../../src/common/rectangle.cpp\
  ../../src/core/display.cpp\
  ../../src/core/eventListener.cpp\
  ../../src/core/exception.cpp\
  ../../src/core/keyboard.cpp\
  ../../src/core/mouse.cpp\
  ../../src/core/resource.cpp\
  ../../src/core/stateManager.cpp\
  ../../src/core/timer.cpp\
  ../../src/graphics/font.cpp\
  ../../src/graphics/model.cpp\
  ../../src/graphics/shader.cpp\
  ../../src/graphics/shaderSet.cpp\
  ../../src/graphics/sprite.cpp\
  ../../src/graphics/texture.cpp\
  ../../src/graphics/vertexFormats.cpp\
  ../../src/math/matrix.cpp\

OBJ = $(SRC:%.cpp=%.o)

.cpp.o :
	$(CXX) -c $< $(CFLAGS) -o $@

all:	$(LIBRARY)

$(LIBRARY):	$(OBJ)
	$(CXX) -o $(LIBRARY) $(OBJ) $(LDFLAGS)

.PHONY : clean
clean:
	rm -f $(OBJ)

install:
	cp liblavish.so /usr/local/lib/
	mkdir -p /usr/local/include/lavish
	mkdir -p /usr/local/include/lavish/common
	mkdir -p /usr/local/include/lavish/core
	mkdir -p /usr/local/include/lavish/graphics
	mkdir -p /usr/local/include/lavish/math
	cp ../../include/lavish/common/*.hpp /usr/local/include/lavish/common/
	cp ../../include/lavish/core/*.hpp /usr/local/include/lavish/core/
	cp ../../include/lavish/graphics/*.hpp /usr/local/include/lavish/graphics/
	cp ../../include/lavish/math/*.hpp /usr/local/include/lavish/math/