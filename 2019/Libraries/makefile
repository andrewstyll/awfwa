CXX = g++
CXXFLAGS = -Wall -g
VPATH = $(SRCDIR):$(TESTDIR):$(INSTALLDIR)

TESTDIR = test
SRCDIR = src
INSTALLDIR = build

OUTPUT_LIST_TEST_FILE = test_linkedlist
LIST_OBJECTS = TestLinkedList.o

OUTPUT_PQ_TEST_FILE = test_priorityqueue
PQ_OBJECTS = TestPriorityQueue.o

testlist: $(OUTPUT_LIST_TEST_FILE)
testpq: $(OUTPUT_PQ_TEST_FILE)

.PHONY: clean
clean:
	rm -f $(SRCDIR)/*.gch
	rm -f $(INSTALLDIR)/*

# link
$(INSTALLDIR)/$(OUTPUT_LIST_TEST_FILE): $(LIST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(INSTALLDIR)/$(OUTPUT_PQ_TEST_FILE): $(PQ_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# compile
$(INSTALLDIR)/$(LIST_OBJECTS): TestLinkedList.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(INSTALLDIR)/$(PQ_OBJECTS): TestPriorityQueue.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
