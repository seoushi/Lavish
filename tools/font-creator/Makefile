CXX = g++

EXECUTABLE = font-tool

SRC= main.cpp\
	utf8_decode.cpp\

OBJ = $(SRC:%.cpp=%.o)

.cpp.o :
	$(CXX) -c $< -o $@

all:	$(EXECUTABLE)

$(EXECUTABLE):	$(OBJ)
	$(CXX) -o $(EXECUTABLE) $(OBJ)

.PHONY : clean
clean:
	rm -f $(OBJ)

