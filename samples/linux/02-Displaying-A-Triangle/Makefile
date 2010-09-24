#compile the library
#include ../../../projects/linux/Makefile

CXX = g++

CFLAGS := -I../../../include -O2 -pipe -Wall -ansi -fPIC
LDFLAGS := -L../../../projects/linux -llavish
#-lGL -lGLU -lGLEW -lSDL_image `sdl-config --cflags --libs` -shared

EXECUTABLE = sample-02

SRC= main.cpp\

OBJ = $(SRC:%.cpp=%.o)

.cpp.o :
	$(CXX) -c $< $(CFLAGS) -o $@

all:	$(EXECUTABLE)

$(EXECUTABLE):	$(OBJ)
	$(CXX) -o $(EXECUTABLE) $(OBJ) $(LDFLAGS)

.PHONY : clean
clean:
	rm -f $(OBJ)
