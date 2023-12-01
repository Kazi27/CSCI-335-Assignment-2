//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#ifndef MEDIANOFMEDIAN_HPP
#define MEDIANOFMEDIAN_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

int medianOfMediansMethod(std::vector<int>& nums, int& duration);

// returns the median of medians of all elements contained between high and low, inclusive
int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);

int medianOfFive(std::vector<int>::iterator a, std::vector<int>::iterator b, std::vector<int>::iterator c, std::vector<int>::iterator d, std::vector<int>::iterator e);

#endif