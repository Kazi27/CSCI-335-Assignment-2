//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#include "QuickSelect.hpp"

//purpose of this func is to find a suitable pivot to provide an even partition
//all of these if and else if statements bascially effectively checks which between mid/high/low is closes to actual middle of the vector to be the pivot
std::vector<int>::iterator choosePivot(std::vector<int>& nums,std::vector<int>::iterator low, std::vector<int>::iterator high)
{
    std::vector<int>::iterator mid = low + (high - low) / 2; //midpoint iterator between low and high
    if (*low < *mid) 
    { 
        if (*mid < *high) 
        {
            return mid; 
        }

        else if (*low < *high)
        {
            return high; 
        }
        
        else
        {
            if (*low < *high) 
            {
                return low; 
            }

            else if (*mid < *high)
            {
                return high; 
            }
            
            else 
            {
                return mid;
            } 
        }
    }
}

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
    std::vector<int>::iterator pivot = choosePivot(nums, low, high); //returns pivot
    std::swap(*pivot, *(high - 1)); //pivot swapped with second to last element
    pivot = high - 1; 
    
    auto i = low; //moves right, looking for stuff smaller than the pivot
    auto j = high - 2; //moves left, looking for stuff bigger than the pivot
    while (true) 
    { 
        while (*i < *pivot) 
        {
            ++i; //move right when smaller than pivot
        }

        while (*j > *pivot) 
        {
            --j; //move left when bigger than pivot
        }

        if (i < j) 
        {
            std::swap(*i, *j); //when they meet or cross swap
        }
        
        else 
        {
            break; 
        }
    } 
    
    std::swap(*i, *pivot); 
    return i; //by the end u have a left part smaller than pivot, right part bigger than pivot
}

void recursiveQuickSelect(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) 
{ 
    while (high - low > 10) //keeps calling itself till the remaining pile size is less than 11
    { 
        std::vector<int>::iterator pivot = hoarePartition(nums, low, high); //divide into two parts
        if (pivot - low < high - pivot) 
        { 
            recursiveQuickSelect(nums, low, pivot); 
            low = pivot + 1; 
        } 
            
        else 
        { 
            recursiveQuickSelect(nums, pivot + 1, high); 
            high = pivot; 
        } 
    } 
    std::sort(low, high); //recursion too deep use nromal sort
}

int quickSelect(std::vector<int>& nums, int& duration) //func declr
{
    auto start = std::chrono::high_resolution_clock::now(); //start time of algo

    recursiveQuickSelect(nums, nums.begin(), nums.end()); 

    auto end = std::chrono::high_resolution_clock::now(); //yea we know

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //kay

    //print the sorted vector (for testing purposes, remove in the final version)
    // std::cout << "Sorted vector by QuickSelect: ";
    // for (int num : nums) 
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << "\n";

    //find & return median of the sorted vector
    int size = nums.size();
    if (size % 2 == 0) //for even-sized vectors
    {
        //return the lesser of the middle elements
        return std::min(nums[size / 2 - 1], nums[size / 2]);
    } 

    else 
    {
        //for odd-sized vectors, return middle element
        return nums[size / 2];
    }
}