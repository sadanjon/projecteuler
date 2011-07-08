CXX=g++
CXXFLAGS=-g -Wall

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

TARGET=sum35

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
