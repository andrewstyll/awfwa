CXX = g++
CXXFLAGS = -Wall -g

TEST_DIR = test/
SRC_DIR = src/
INSTALL_DIR = build/

VPATH = $(TEST_DIR)

OUTPUT_LIST_TEST = test_linkedlist.out
LIST_SRC = TestLinkedList.cpp

OUTPUT_PQ_TEST = test_priorityqueue.out
PQ_SRC = TestPriorityQueue.cpp

LIST_OUT = $(addprefix $(INSTALL_DIR), $(OUTPUT_LIST_TEST))
LIST_OBJ = $(addprefix $(INSTALL_DIR), $(patsubst %.cpp, %.o, $(LIST_SRC)))

PQ_OUT = $(addprefix $(INSTALL_DIR), $(OUTPUT_PQ_TEST))
PQ_OBJ = $(addprefix $(INSTALL_DIR), $(patsubst %.cpp, %.o, $(PQ_SRC)))

listtest: $(LIST_OUT)
pqtest: $(PQ_OUT)

.PHONY: clean
clean:
	rm -f $(SRC_DIR)*.gch
	rm -f $(INSTALL_DIR)*

# link
$(LIST_OUT): $(LIST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(PQ_OUT): $(PQ_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# compile
$(LIST_OBJ):  $(INSTALL_DIR)%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PQ_OBJ):  $(INSTALL_DIR)%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
