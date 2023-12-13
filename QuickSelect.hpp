// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 2
//this is the working version giving me points, below is another version, cpp file contains pervious versions I tested before autograder was up

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>

std::vector<int>::iterator medianof3 (std::vector<int>& nums, std::vector<int>::iterator left, std::vector<int>::iterator right) //get yo median u need for hoare parititon
{
    std::vector<int>::iterator center = left; ///ITERATOR TO MID ELEMENT

    std::advance(center, std::distance(left, right) / 2); 
 
    if((*left == *center && *left == *right) || *left == *center || *left == *right) //CONDITION cehcks to determine pivot based on YT vid
    {
        std::iter_swap(left, right);
    }
    
    else if(*center == *right) 
    {
        std::iter_swap(center, right);
    }
    
    else
    {

        if((*left < *center && *center < *right) || (*right < *center && *center < *left ))
        {
            std::iter_swap(center, right);
        }
        
        else if((*center < *left  && *left < *right) || (*right < *left && *left < *center))
        {
            std::iter_swap(left, right);
        }
        
        else
        {
            return right;
        }

    }
    return right;
}

// hoarePartition precondition: left points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by right.
// hoarePartition returns an iterator to the pivot after it's placed.
// Note that this implementation of hoarePartition makes it usable with different pivot selection methods, but also requires that you select your pivot and swap it into the last position prior to calling hoarePartition.
std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator left, std::vector<int>::iterator right)
{
    std::vector<int>::iterator pivot = medianof3(nums, left, right); //get ut pivot
    std::vector<int>::iterator left1 = left; //left iterator
    std::vector<int>::iterator right1 = pivot - 1; //roight iterator
    
    while(true) //loop till left and right iterators cross each other
    {
        while(left1 < pivot && *left1 < *pivot) //move left to right when elements r smaller than pivot
        {
            ++left1;
        }
        
        while(right1 > left1 && *right1 > *pivot) //oppsite of above, move right to left when elements r biggs than pivot
        {
            --right1;
        }
        
        if(left1 >= right1) //THEY MET
        {
            break;
        }

        std::iter_swap(left1, right1); //swap
        ++left1;
        --right1;
    }

    std::iter_swap(left1, pivot); //swap and now the pivot is in its proper palce
    return left1; //return pivot
}

void quickSelect (std::vector<int>& nums, std::vector<int>::iterator left, std::vector<int>::iterator right, std::vector<int>::iterator center)
{
    if(right <= left + 9)
    {
        std::sort(left, right + 1); //if input small just sort
    }

    std::vector<int>::iterator median = hoarePartition(nums, left, right); //parition and get median

    if(median == center)
    {
        return;
    }
    
    else if (median < center)
    {
        quickSelect(nums, median + 1, right, center); //recurs call to right partiiton ( < center )
    }
    
    else
    {
        quickSelect(nums, left, median - 1, center); //recurs call to left partion ( > center )
    }
}

int quickSelect (std::vector<int>& nums, int& duration) //simple stuff, we do this everywhere
{
    auto start = std::chrono::steady_clock::now();

    quickSelect(nums, nums.begin(), nums.end() - 1, nums.begin() + (nums.size() - 1)/2);

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return *(nums.begin() + (nums.size() - 1)/2);
}

//OLD VERSION
// #ifndef QUICKSELECT_HPP
// #define QUICKSELECT_HPP //hpp stuff

// #include <iostream> //guards
// #include <vector>
// #include <algorithm>
// #include <chrono>
// #include <fstream>

// int quickSelect (std::vector<int>& nums, int& duration)
// {
//      if (nums.empty())
//     {
//         return -1; 
//     }

//     int n = nums.size();
//     int k = n / 2; 

//     auto start = std::chrono::high_resolution_clock::now(); //start time of algo

//     if (n % 2 == 0) {
//         k = n / 2 - 1;
//                 // int mid1 = quickSelectHelper(nums, nums.begin(), nums.end() - 1, k - 1);
//          quickSelectHelper(nums, nums.begin(), nums.end() - 1, k);
//     } else {
//         k = n / 2;
//          quickSelectHelper(nums, nums.begin(), nums.end() - 1, k);
//     }

//     auto end = std::chrono::high_resolution_clock::now(); //yea we know

//     duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //kay

//     //print the sorted vector (for testing purposes, remove in the final version)
//     // std::cout << "Sorted vector by QuickSelect: ";
//     // for (int num : nums) 
//     // {
//     //     std::cout << num << " ";
//     // }
//     // std::cout << "\n";

//     //find & return median of the sorted vector
//     int size = nums.size();
//     if (size % 2 == 0) //for even-sized vectors
//     {
//         //return the lesser of the middle elements
//         return std::min(nums[size / 2 - 1], nums[size / 2]);
//     } 

//     else 
//     {
//         //for odd-sized vectors, return middle element
//         return nums[size / 2];
//     }
// }

// // hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
// // hoarePartition returns an iterator to the pivot after it's placed.
// //Note that this implementation of hoarePartition makes it usable with different pivot selection methods, but also requires that you select your pivot and swap it into the last position prior to calling hoarePartition.
// std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
// {
//     // std::vector<int>::iterator pivot = choosePivot(nums, low, high); //returns pivot
//     // std::swap(*pivot, *(high - 1)); //pivot swapped with second to last element
//     // pivot = high - 1; 
    
//     // auto i = low; //moves right, looking for stuff smaller than the pivot
//     // auto j = high - 2; //moves left, looking for stuff bigger than the pivot
//     // while (true) 
//     // { 
//     //     while (*i < *pivot) 
//     //     {
//     //         ++i; //move right when smaller than pivot
//     //     }

//     //     while (*j > *pivot) 
//     //     {
//     //         --j; //move left when bigger than pivot
//     //     }

//     //     if (i < j) 
//     //     {
//     //         std::swap(*i, *j); //when they meet or cross swap
//     //     }
        
//     //     else 
//     //     {
//     //         break; 
//     //     }
//     // } 
    
//     // std::swap(*i, *pivot); 
//     // return i; //by the end u have a left part smaller than pivot, right part bigger than pivot
//     auto pivot = medianOfThree(low, low + std::distance(low, high) / 2, high);
//     std::iter_swap(pivot, high);
//     auto i = low;
//     auto j = high - 1;
//     while (true)
//     {
//         while (i < j && *i < *high)
//         {
//             i++;
//         }
//         while (j > i && *j >= *high)
//         {
//             j--;
//         }
//         if (i >= j)
//         {
//             break;
//         }
//         std::swap(*i, *j);
//     }
//     std::swap(*i, *high);
//     return i;
// }

// int quickSelectHelper(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int k)
// {
//     if (high - low < 10)
//     {
//         std::sort(low, high + 1); 
//         return *(low + k);
//     }
//     auto partition = hoarePartition(nums, low, high);
//     int pivotDist = std::distance(low, partition);

//     if (pivotDist == k)
//     {
//         return *partition;
//     }
//     else if (pivotDist > k)
//     {
//         return quickSelectHelper(nums, low, partition - 1, k);
//     }
//     else
//     {
//         return quickSelectHelper(nums, partition + 1, high, k - pivotDist - 1);
//     }
// }

// std::vector<int>::iterator medianOfThree(std::vector<int>::iterator first, std::vector<int>::iterator middle, std::vector<int>::iterator last)
// {
//     if (*first > *middle)
//     {
//         if (*first < *last) 
//             return first;
//         else if (*middle > *last) 
//             return middle;
//         else 
//             return last;
//     }
//     else
//     {
//         if (*first > *last) 
//             return first;
//         else if (*middle < *last) 
//             return middle;
//         else 
//             return last;
//     }
// }

// #endif