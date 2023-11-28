#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

//worstCaseQuickSelect generates a worst-case input for a quickselect that uses median-of-3 partitioning. The input it generates must be of length 20,000, and contain each number from 1-20000 once.
std::vector<int> worstCaseQuickSelect();

#endif