CXX = g++
CXXFLAGS = -Wall -g
VPATH = $(SRC_DIR):$(TEST_DIR):$(INSTALL_DIR)

TEST_DIR = test
SRC_DIR = src
INSTALL_DIR = build

OUTPUT_LIST_TEST_FILE = test_linkedlist.out
LIST_OBJECTS = TestLinkedList.o

OUTPUT_PQ_TEST_FILE = test_priorityqueue.out
PQ_OBJECTS = TestPriorityQueue.o MinComparator.o MaxComparator.o

testlist: $(OUTPUT_LIST_TEST_FILE)
testpq: $(OUTPUT_PQ_TEST_FILE)

.PHONY: clean
clean:
	rm -f $(SRC_DIR)/*.gch
	rm -f $(INSTALL_DIR)/*

# link
$(INSTALL_DIR)/$(OUTPUT_LIST_TEST_FILE): $(LIST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(INSTALL_DIR)/$(OUTPUT_PQ_TEST_FILE): $(PQ_OBJECTS)
	$(CXX) $(PQ_OBJECTS) -o $@

# compile
$(INSTALL_DIR)/$(LIST_OBJECTS): TestLinkedList.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(INSTALL_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<
