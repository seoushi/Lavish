#compile the library
#include ../../../projects/linux/Makefile

CXX = g++

CFLAGS := -I../../../include -O2 -pipe -Wall -ansi -fPIC
LDFLAGS := -L../../../projects/linux -llavish

EXECUTABLE = sample-05

SRC= main.cpp\
	FPSCamera.cpp\

OBJ = $(SRC:%.cpp=%.o)

.cpp.o :
	$(CXX) -c $< $(CFLAGS) -o $@

all:	$(EXECUTABLE)

$(EXECUTABLE):	$(OBJ)
	$(CXX) -o $(EXECUTABLE) $(OBJ) $(LDFLAGS)

.PHONY : clean
clean:
	rm -f $(OBJ)
