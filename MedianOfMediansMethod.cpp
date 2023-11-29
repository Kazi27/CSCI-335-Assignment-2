#include "MedianOfMediansMethod.hpp"
#include "QuickSelect.hpp"

int medianOfFive(std::vector<int>::iterator a, std::vector<int>::iterator b, std::vector<int>::iterator c, std::vector<int>::iterator d, std::vector<int>::iterator e) 
{ 
    int arr[] = { *a, *b, *c, *d, *e }; 
    std::sort(arr, arr + 5);
    return arr[2]; // Median of the sorted array 
}

int medianOfMediansMethod(std::vector<int>& nums, int& duration)
{
    auto start = std::chrono::high_resolution_clock::now(); //start time of algo

    int result = medianOfMedians(nums, nums.begin(), nums.end());

    auto end = std::chrono::high_resolution_clock::now(); //yea we know

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //kay

    return result;
}

int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
    std::vector<int> medians; 
    while (low < high) 
    { 
        std::vector<int>::iterator groupHigh = low + 5; 
        if (groupHigh > high) 
        { 
            groupHigh = high; 
        } 
        
        if (groupHigh - low <= 24) 
        { 
            // Base case: Use std::sort for small subarrays 
            std::sort(low, groupHigh); 
            medians.push_back(*(low + (groupHigh - low) / 2)); 
        } 
        
        else 
        { 
            // Continue with recursive call 
            int median = medianOfFive(low, low + 1, low + 2, low + 3, low + 4); 
            medians.push_back(median); 
        } 
        
        low += 5; 
    } 
    //return quickSelect(medians, medians.size() / 2); 
}