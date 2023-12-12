//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#ifndef MEDIANOFMEDIAN_HPP
#define MEDIANOFMEDIAN_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

int medianOfMediansMethod(std::vector<int>& nums, int& duration)
{
    auto start = std::chrono::high_resolution_clock::now();

    recursiveQuickSelect(nums, nums.begin(), nums.end()); //ur gonna find medians of groups of 5 and then find the medians of all the medians you get till theres only one median left

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Print the sorted vector (for testing purposes, remove in the final version)
    // std::cout << "Sorted vector by Median of Medians: ";
    // for (int num : nums) {
    //     std::cout << num << " ";
    // }
    // std::cout << "\n";

    int size1 = nums.size(); //using size1 here because used size before
    if (size1 % 2 == 0) //for even-sized vectors
    {
        //return the lesser of the middle elements
        return std::min(nums[size1 / 2 - 1], nums[size1 / 2]);
    } 

    else 
    {
        //for odd-sized vectors, return middle element
        return nums[size1 / 2];
    }
}

// returns the median of medians of all elements contained between high and low, inclusive
int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
    int groupSize = 5; //so ur group size is 5 an ur gonna find the median in this group of 5
    int size = high - low + 1;
    int numGroups = size / groupSize;

    //a vector to store medians of groups
    std::vector<int> medians;

    //find median of each group
    for (int i = 0; i < numGroups; ++i) 
    {
        auto groupLow = low + i * groupSize;
        auto groupHigh = groupLow + groupSize - 1;
        int median = medianOfFive(groupLow, groupHigh);
        medians.push_back(median);
    }

    //if leftover elements, find the median of those
    if (size % groupSize > 0) 
    {
        auto groupLow = low + numGroups * groupSize;
        auto groupHigh = low + size - 1;
        int median = medianOfFive(groupLow, groupHigh);
        medians.push_back(median);
    }

    //recursively find  median of medians
    if (medians.size() > 1) 
    {
        return medianOfMedians(medians, medians.begin(), medians.end());
    } 
    
    else 
    {
        return medians[0];
    }
}

int medianOfFive(std::vector<int>::iterator a, std::vector<int>::iterator b, std::vector<int>::iterator c, std::vector<int>::iterator d, std::vector<int>::iterator e)
{
    std::sort(low, high);
    return *(low + (high - low) / 2);
}

#endif