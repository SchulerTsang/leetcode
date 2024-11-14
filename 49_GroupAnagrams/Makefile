# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -std=c++11

# Libraries to link with
# LIBS = -lworkflow # Replace with your actual libraries
LIBS =  # Replace with your actual libraries

# Source files (automatically include all .cpp files in the current directory)
SRCS = $(wildcard *.cpp)

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = main

# Default target to build the executable
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild rule
rebuild: clean $(TARGET)

# Phony targets
.PHONY: all clean rebuild

