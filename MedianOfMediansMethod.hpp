//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2
//this is the working version giving me points, below is another version, cpp file contains pervious versions I tested before autograder was up

#ifndef MEDIANOFMEDIANSMETHOD_HPP
#define MEDIANOFMEDIANSMETHOD_HPP

#include <algorithm>
#include <vector>
#include <chrono>
#include <iostream>
int medianOfFive(std::vector<int>& nums, int start, int end) 
{
    std::sort(nums.begin() + start, nums.begin() + end); //use std stort first
    return nums[start + (end - start) / 2]; //this is the median
}

int medianOfMedians(std::vector<int>& nums, int low, int high) 
{
    if (high - low <= 24) //if subarray is <= 24 elements, find median directly
    {
        std::nth_element(nums.begin() + low, nums.begin() + low + (high - low) / 2, nums.begin() + high);
        return nums[low + (high - low) / 2];
    }

    std::vector<int> storeMedians; //we wills tore the medians in here
    for (int it = low; it < high; it += 5) //chunks of 5
    {
        int arrayEnd = std::min(it + 5, high); //end of array
        if (arrayEnd - it >= 3) 
        {
            storeMedians.push_back(medianOfFive(nums, it, arrayEnd)); //find the median if theres atleast 3 elementrs in the subarray
        }
    }

    return medianOfMedians(storeMedians, 0, storeMedians.size()); //recursive call
}


int medianOfMediansMethod(std::vector<int>& nums, int& duration) //basic stuff that we did everywhere
{
    auto start = std::chrono::high_resolution_clock::now();

    int median = medianOfMedians(nums, 0, nums.size());

    auto end = std::chrono::high_resolution_clock::now();
    
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return median;
}

#endif 

//THIS VERSION WORKED WHEN I HAD CPP FILE WITH MAKE REBUILD
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <chrono>

// int medianOfMediansMethod(std::vector<int>& nums, int& duration) //??how to work
// {
//     auto start = std::chrono::high_resolution_clock::now();
//     auto end = std::chrono::high_resolution_clock::now();
//     duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//     // Print the sorted vector (for testing purposes, remove in the final version)
//     // std::cout << "Sorted vector by Median of Medians: ";
//     // for (int num : nums) {
//     //     std::cout << num << " ";
//     // }
//     // std::cout << "\n";

//     int size1 = nums.size(); //using size1 here because used size before
//     if (size1 % 2 == 0) //for even-sized vectors
//     {
//         //return the lesser of the middle elements
//         return std::min(nums[size1 / 2 - 1], nums[size1 / 2]);
//     } 

//     else 
//     {
//         //for odd-sized vectors, return middle element
//         return nums[size1 / 2];
//     }
// }

// int medianOfFive(std::vector<int> nums, std::vector<int>::iterator a, std::vector<int>::iterator b, std::vector<int>::iterator c, std::vector<int>::iterator d, std::vector<int>::iterator e) 
// {
//     std::vector<int>::iterator temporary;

//     // Ensure a < b and b < d
//     if (*b < *a) 
//     {
//         temporary = a; 
//         a = b; 
//         b = temporary;
//     }

//     if (*d < *c) 
//     {
//         temporary = c; 
//         c = d; 
//         d = temporary;
//     }

//     // Eliminate the lowest
//     if (*c < *a) 
//     {
//         temporary = b; 
//         b = d; 
//         d = temporary;
//         c = a;
//     }

//     // Get e in
//     a = e;

//     // Ensure a < b and b < d
//     if (*b < *a) 
//     {
//         temporary = a; 
//         a = b; 
//         b = temporary;
//     }

//     // Eliminate another lowest (remaining: a, b, d)
//     if (*a < *c) 
//     {
//         temporary = b; 
//         b = d; 
//         d = temporary;
//         a = c;
//     }

//     if (*d < *a) 
//     {
//         return *d;
//     }
//     return *a;
// }

// std::vector<int>::iterator hoarePartition(std::vector<int> nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int pivot) 
// {
//     auto i = low, j = high - 1;
//     auto it = low;

//     // Find the iterator pointing to the pivot value
//     while (*it != pivot) 
//     {
//         it++;
//     }

//     // Swap the pivot to the end of the range
//     std::iter_swap(it, high);

//     // Partition the range
//     while (true) 
//     {
//         while (*i < pivot) 
//         {
//             ++i;
//         }

//         while (*j > pivot) 
//         {
//             --j;
//         }

//         if (std::distance(i, j) > 0) 
//         {
//             std::iter_swap(i, j);
//         } 
        
//         else 
//         {
//             break;
//         }
//     }

//     // Restore pivot to its correct position
//     std::iter_swap(i, high);
//     return i;
// }

// int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) 
// {
//     if (nums.size() > 24) 
//     {
//         std::vector<int> medians;

//         auto it = low;
//         for (; it + 4 < high; it += 5) 
//         {
//             int median = medianOfFive(nums, it, it + 1, it + 2, it + 3, it + 4);
//             medians.push_back(median);
//         }

//         // Add last remaining elements between 3 and 5
//         std::vector<int> temporary;
//         if (std::distance(it, nums.end()) > 2) 
//         {
//             while (std::distance(it, nums.end()) > 0) 
//             {
//                 temporary.push_back(*it);
//                 it++;
//             }
//             std::sort(temporary.begin(), temporary.end());
//             int median = temporary[1];
//         }

//         // Recursive call to find the median of medians
//         int pivot = medianOfMedians(medians, medians.begin(), medians.end() - 1);
//         auto pivotIndex = hoarePartition(nums, low, high, pivot);

//         // The rest of the code seems incomplete, and the pivotIndex is not used.

//     }
//     std::sort(nums.begin(), nums.end());
//     return (nums.size() % 2 == 0 ? nums[nums.size() / 2 - 1] : nums[nums.size() / 2]);
// }


//old version -- lot of errors
// #ifndef MEDIANOFMEDIAN_HPP
// #define MEDIANOFMEDIAN_HPP //hpp stuff

// #include <iostream> //guards
// #include <vector>
// #include <algorithm>
// #include <chrono>
// #include <fstream>

// int medianOfMediansMethod(std::vector<int>& nums, int& duration)
// {
//     auto start = std::chrono::high_resolution_clock::now();

//     recursiveQuickSelect(nums, nums.begin(), nums.end()); //ur gonna find medians of groups of 5 and then find the medians of all the medians you get till theres only one median left

//     auto end = std::chrono::high_resolution_clock::now();
//     //duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//     // Print the sorted vector (for testing purposes, remove in the final version)
//     // std::cout << "Sorted vector by Median of Medians: ";
//     // for (int num : nums) {
//     //     std::cout << num << " ";
//     // }
//     // std::cout << "\n";

//     int size1 = nums.size(); //using size1 here because used size before
//     if (size1 % 2 == 0) //for even-sized vectors
//     {
//         //return the lesser of the middle elements
//         return std::min(nums[size1 / 2 - 1], nums[size1 / 2]);
//     } 

//     else 
//     {
//         //for odd-sized vectors, return middle element
//         return nums[size1 / 2];
//     }
// }

// // returns the median of medians of all elements contained between high and low, inclusive
// int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
// {
//     int groupSize = 5; //so ur group size is 5 an ur gonna find the median in this group of 5
//     int size = high - low + 1;
//     int numGroups = size / groupSize;

//     //a vector to store medians of groups
//     std::vector<int> medians;

//     //find median of each group
//     for (int i = 0; i < numGroups; ++i) 
//     {
//         auto groupLow = low + i * groupSize;
//         auto groupHigh = groupLow + groupSize - 1;
//         int median = medianOfFive(groupLow, groupHigh);
//         medians.push_back(median);
//     }

//     //if leftover elements, find the median of those
//     if (size % groupSize > 0) 
//     {
//         auto groupLow = low + numGroups * groupSize;
//         auto groupHigh = low + size - 1;
//         int median = medianOfFive(groupLow, groupHigh);
//         medians.push_back(median);
//     }

//     //recursively find  median of medians
//     if (medians.size() > 1) 
//     {
//         return medianOfMedians(medians, medians.begin(), medians.end());
//     } 
    
//     else 
//     {
//         return medians[0];
//     }
// }

// int medianOfFive(std::vector<int>::iterator a, std::vector<int>::iterator b, std::vector<int>::iterator c, std::vector<int>::iterator d, std::vector<int>::iterator e)
// {
//     std::sort(low, high);
//     return *(low + (high - low) / 2);
// }

// #endif