CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

SRC_DIR = src/
INSTALL_DIR = build/

OUTPUT_DIJKSTRA = dijkstra.out
DIJKSTRA_SRC = Dijkstra.cpp GraphNode.cpp

DIJKSTRA_OUT = $(addprefix $(INSTALL_DIR), $(OUTPUT_DIJKSTRA))
DIJKSTRA_OBJ = $(addprefix $(INSTALL_DIR), $(patsubst %.cpp, %.o, $(DIJKSTRA_SRC)))

dijkstra: $(DIJKSTRA_OUT)

.PHONY: clean
clean:
	rm -f $(SRC_DIR)*.gch
	rm -f $(INSTALL_DIR)*

# link
$(DIJKSTRA_OUT): $(DIJKSTRA_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# compile
$(DIJKSTRA_OBJ): $(INSTALL_DIR)%.o : $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
