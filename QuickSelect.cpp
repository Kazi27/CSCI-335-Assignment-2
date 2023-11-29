#include "QuickSelect.hpp"

std::vector<int>::iterator choosePivot(std::vector<int>& nums,std::vector<int>::iterator low, std::vector<int>::iterator high)
{
    std::vector<int>::iterator mid = low + (high - low) / 2; 
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

std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high )
{
    std::vector<int>::iterator pivot = choosePivot(nums, low, high); 
    std::swap(*pivot, *(high - 1)); 
    pivot = high - 1; 
    
    auto i = low; 
    auto j = high - 2; 
    while (true) 
    { 
        while (*i < *pivot) 
        ++i; 
        while (*j > *pivot) 
        --j; 
        if (i < j) 
        std::swap(*i, *j); 
        
        else 
            break; 
    } 
    
    std::swap(*i, *pivot); 
    return i;
}

void recursiveQuickSelect(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) 
{ 
    while (high - low > 10) 
    { 
        std::vector<int>::iterator pivot = hoarePartition(nums, low, high); 
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
    std::sort(low, high); 
}

int quickSelect (std::vector<int>& nums, int& duration) //func declr
{
    auto start = std::chrono::high_resolution_clock::now(); //start time of algo

    recursiveQuickSelect(nums, nums.begin(), nums.end()); 

    auto end = std::chrono::high_resolution_clock::now(); //yea we know

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //kay

    //print the sorted vector (for testing purposes, remove in the final version)
    std::cout << "Sorted vector by QuickSelect: ";
    for (int num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 1;
}