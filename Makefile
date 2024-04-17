CC = g++
CXXFLAGS = -std=c++20 -Wall
TARGET = main

BUILD_FOLDER := build
INCLUDE_FOLDER := include
SRC_FOLDER := src

# INCLUDES := $(wildcard include/*.hpp)
# SOURCES := $(wildcard src/*.cpp)
# OBJECTS := $(patsubst src/%.cpp,build/%.o, $(SOURCES))

$(BUILD_FOLDER)/$(TARGET): $(BUILD_FOLDER)/node.o $(BUILD_FOLDER)/graph.o $(BUILD_FOLDER)/main.o
	$(CC) $(CXXFLAGS) -o $(TARGET) $(BUILD_FOLDER)/*.o

$(BUILD_FOLDER)/node.o: $(INCLUDE_FOLDER)/types.hpp $(INCLUDE_FOLDER)/node.hpp $(SRC_FOLDER)/node.cpp
	$(CC) $(CXXFLAGS) -I ${INCLUDE_FOLDER} -c $(SRC_FOLDER)/node.cpp -o $(BUILD_FOLDER)/node.o

$(BUILD_FOLDER)/graph.o: $(INCLUDE_FOLDER)/types.hpp $(INCLUDE_FOLDER)/graph.hpp $(INCLUDE_FOLDER)/node.hpp $(SRC_FOLDER)/graph.cpp
	$(CC) $(CXXFLAGS) -I ${INCLUDE_FOLDER} -c $(SRC_FOLDER)/graph.cpp -o $(BUILD_FOLDER)/graph.o

$(BUILD_FOLDER)/main.o: $(INCLUDE_FOLDER)/types.hpp $(INCLUDE_FOLDER)/node.hpp $(INCLUDE_FOLDER)/graph.hpp $(SRC_FOLDER)/main.cpp
	$(CC) $(CXXFLAGS) -I ${INCLUDE_FOLDER} -c $(SRC_FOLDER)/main.cpp -o $(BUILD_FOLDER)/main.o

.PHONY: clean
clean:
	@rm -f $(BUILD_FOLDER)/*.o main