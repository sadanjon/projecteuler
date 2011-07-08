CXX=g++
CXXFLAGS=-g -Wall

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

TARGET=sum_even_fib

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
