//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

int halfSelectionSort (std::vector<int>& nums, int& duration) //func declr
{
    auto start_time = std::chrono::high_resolution_clock::now(); //start time of algo

    const int size = nums.size(); //size of input vector

    //const int limit = size / 2; //caalc limit (half of vector size)

    if (size > 50000) //if the input size is too large for the algo
    {
        std::cout << "Input too big for HalfSelectionSort (>50,000 elements).\n";
        duration = -1; //-1 as duration cause ur a failure due to large input size lmao
        return -1;
    }

    auto mid = nums.begin() + nums.size()/2; //halfway midpoint
    for (auto i = nums.begin(); i < mid + 1; ++i) //iteratre thru vector to find the ith smallest element & move it to the ith pos like find first smallest, put it first spot, go halfway
    {
        auto min = i; //initialize index of the min element to curr iteration index i

        for (auto j = i + 1; j < nums.end(); ++j) //iterate thru unsorted portion to find the minimum element remember i is till midpoint, j is from midpoint till end
        {
            if (*j < *min) //if ur current element is smaller than element at min_index, 
            {
                min = j; //thats ur new min
            }
        }
        std::iter_swap(min, i); //swap curr element w/ the min element from unsorted portion
    }

    auto end_time = std::chrono::high_resolution_clock::now(); //end time of algo

    //duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count(); //duration of the algo

    //print sorted vector but remove in the final
    //     // std::cout << "Sorted vector by HalfSelectionSort: ";
    //     // for (const auto& num : nums) 
    //     // {
    //     //     std::cout << num << " ";
    //     // }
    //     // std::cout << "\n";

    //return the median, specs say its the lesser of the two middle elements IF ITS EVEN, if odd just return the middle one
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

#endif