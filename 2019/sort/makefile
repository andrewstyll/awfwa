CXX = g++
CXXFLAGS = -Wall -g

OBJECTS = Main.o

# Build the executable
main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# object dependencies
Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

$(OBJECTS): LinkedList.hpp Node.hpp
