# Makefile

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iheaders
SRC_DIR = sources
OBJ_DIR = obj

SOURCES = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = datos

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o *.o $(TARGET)
