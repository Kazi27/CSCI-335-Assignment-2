#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

int halfHeapSort(std::vector<int>& nums, int& duration);

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole);

void buildHeap(std::vector<int>& heap);

#endif