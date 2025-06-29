# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Source files
SRCS = main.cpp lexer.cpp parser.cpp

# Output executable
TARGET = main

# Default target: build and run
all: $(TARGET)
	./$(TARGET)

# Build target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Rule for cleaning up build files
clean:
	del /Q $(TARGET).exe