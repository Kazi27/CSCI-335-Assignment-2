//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

int inPlaceMergeSort (std::vector<int>& nums, int& duration);
void merge(std::vector<int>& nums, size_t left, size_t mid, size_t right);
void mergeSortRec(std::vector<int>& nums, size_t left, size_t right);

#endif