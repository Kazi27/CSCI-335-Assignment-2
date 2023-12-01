CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

PROG ?= main
OBJS = main.cpp HalfSelectionSort.cpp StandardSort.cpp MergeSort.cpp InPlaceMergeSort.cpp HalfHeapSort.cpp QuickSelect.cpp MedianOfMediansMethod.cpp WorstCaseQuickSelect.cpp

all: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(PROG) *.o

rebuild: clean all