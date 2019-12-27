#Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -ldl -c

# Executable
EXEC = SL

# Source files and headers
SOURCES = vector.cpp
HEADERS = vector.h

# Recipes
$(EXEC):
	$(CXX) $(CXXFLAGS) $(SOURCES) $(HEADERS)

clean:
	rm *.out *.dYSM *.o