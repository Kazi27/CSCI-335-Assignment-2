#include "MergeSort.hpp"


void printVector(const std::vector<int>& nums) 
{
    for (const auto& num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void mergeSortHelper(std::vector<int>& nums, int left, int right) 
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the left and right halves
        mergeSortHelper(nums, left, mid);
        mergeSortHelper(nums, mid + 1, right);

        // Merge the sorted halves
        std::vector<int> temp(right - left + 1);
        std::merge(nums.begin() + left, nums.begin() + mid + 1, nums.begin() + mid + 1, nums.begin() + right + 1, temp.begin());
        std::copy(temp.begin(), temp.end(), nums.begin() + left);
    }
}

int mergeSort(std::vector<int>& nums, int& duration) 
{
    auto start = std::chrono::high_resolution_clock::now();

    // Perform merge sort
    mergeSortHelper(nums, 0, nums.size() - 1);

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Print the sorted vector
    printVector(nums);

    // Find and return the median
    int size = nums.size();
    if (size % 2 == 0) 
    {
        // For even-sized vectors, return the lesser of the middle elements
        return std::min(nums[size / 2 - 1], nums[size / 2]);
    } 
    
    else 
    {
        // For odd-sized vectors, return the middle element
        return nums[size / 2];
    }
}