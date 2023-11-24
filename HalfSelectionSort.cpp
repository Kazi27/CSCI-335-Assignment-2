#include "HalfSelectionSort.hpp"

int halfSelectionSort(std::vector<int>& nums, int& duration) 
{
    auto start_time = std::chrono::high_resolution_clock::now();

    const int size = nums.size();
    const int limit = size / 2;

    if (size > 50000) 
    {
        std::cout << "Input too big for HalfSelectionSort (>50,000 elements).\n";
        duration = -1; // Indicate failure due to large input size
        return -1;
    }

    for (int i = 0; i < limit; ++i) 
    {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) 
        {
            if (nums[j] < nums[min_index]) 
            {
                min_index = j;
            }
        }
        std::swap(nums[i], nums[min_index]);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    // Print the vector (for testing purposes, remove in final version)
    std::cout << "Sorted vector by HalfSelectionSort: ";
    for (const auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return (nums[limit - 1] + nums[limit]) / 2; // Return the lesser of the 2 middle elements
}