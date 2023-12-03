#include "MedianOfMediansMethod.hpp"
#include "QuickSelect.hpp"

// Function to find the median of a small array (size <= 5)
int medianOfFive(std::vector<int>::iterator low, std::vector<int>::iterator high) {
    std::sort(low, high);
    return *(low + (high - low) / 2);
}

// Function to find the median of medians
int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    int groupSize = 5;
    int size = high - low + 1;
    int numGroups = size / groupSize;

    // Create a vector to store the medians of groups
    std::vector<int> medians;

    // Find the median of each group
    for (int i = 0; i < numGroups; ++i) {
        auto groupLow = low + i * groupSize;
        auto groupHigh = groupLow + groupSize - 1;
        int median = medianOfFive(groupLow, groupHigh);
        medians.push_back(median);
    }

    // If there are leftover elements, find the median of those
    if (size % groupSize > 0) {
        auto groupLow = low + numGroups * groupSize;
        auto groupHigh = low + size - 1;
        int median = medianOfFive(groupLow, groupHigh);
        medians.push_back(median);
    }

    // Recursively find the median of medians
    if (medians.size() > 1) {
        return medianOfMedians(medians, medians.begin(), medians.end());
    } else {
        return medians[0];
    }
}

// Median of Medians method
int medianOfMediansMethod(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    recursiveQuickSelect(nums, nums.begin(), nums.end());

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Print the sorted vector (for testing purposes, remove in the final version)
    // std::cout << "Sorted vector by Median of Medians: ";
    // for (int num : nums) {
    //     std::cout << num << " ";
    // }
    // std::cout << "\n";

    // Find and return the median of the sorted vector
    int size = nums.size();
    if (size % 2 == 0) {
        // Return the lesser of the middle elements
        return std::min(nums[size / 2 - 1], nums[size / 2]);
    } else {
        // For odd-sized vectors, return the middle element
        return nums[size / 2];
    }
}