CXX = g++
CXXFLAGS = -Wall -g
VPATH = $(SRCDIR):$(TESTDIR):$(INSTALLDIR)

TESTDIR = test
SRCDIR = src
INSTALLDIR = build

OUTPUT_LIST_TEST_FILE = test_linkedlist
LIST_OBJECTS = TestLinkedList.o

testlist: $(OUTPUT_LIST_TEST_FILE)

.PHONY: clean
clean:
	rm -f $(SRCDIR)/*.gch
	rm -f $(INSTALLDIR)/*

# link
$(INSTALLDIR)/$(OUTPUT_LIST_TEST_FILE): $(LIST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(LIST_OBJECTS:.o=.d)

# compile
$(INSTALLDIR)/TestLinkedList.o: TestLinkedList.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
