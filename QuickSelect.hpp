//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

int quickSelect (std::vector<int>& nums, int& duration);

// hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
// hoarePartition returns an iterator to the pivot after it's placed.
//Note that this implementation of hoarePartition makes it usable with different pivot selection methods, but also requires that you select your pivot and swap it into the last position prior to calling hoarePartition.
std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);

void recursiveQuickSelect(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
std::vector<int>::iterator choosePivot(std::vector<int>& nums,std::vector<int>::iterator low, std::vector<int>::iterator high);

#endif