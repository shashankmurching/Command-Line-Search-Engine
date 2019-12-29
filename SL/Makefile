#Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -ldl

# Executable
EXEC = SL
TEST = test

# Source files and headers
SOURCES = 
HEADERS = vector.h
TESTS = test_vector.cpp

# Recipes
$(EXEC):
	$(CXX) $(CXXFLAGS) -c $(SOURCES) $(HEADERS)

$(TEST):
	$(CXX) $(CXXFLAGS) $(SOURCES) $(TESTS) $(HEADERS) 

clean:
	rm *.out *.dYSM *.o