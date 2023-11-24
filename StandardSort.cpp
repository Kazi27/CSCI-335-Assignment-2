#include "StandardSort.hpp"

int standardSort(std::vector<int>& nums, int& duration)
{
    //clock
    auto start = std::chrono::high_resolution_clock::now();

    //std::sort to sort the vector
    std::sort(nums.begin(), nums.end());

    //end clock
    auto stop = std::chrono::high_resolution_clock::now();

    //calc duration
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

    //prlly dont inclde this in the final version but this prints out sorted vector
    std::cout << "Sorted vector: ";
    for (int num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // clculate the median
    int size = nums.size();
    int median = (nums[size / 2 - 1] + nums[size / 2]) / 2;

    return median;
}