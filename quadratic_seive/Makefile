CXX = g++
CXXFLAGS = -g -Wall 

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

TARGET = main

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
