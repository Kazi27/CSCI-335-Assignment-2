#include "InPlaceMergeSort.hpp"

int inPlaceMergeSort(std::vector<int>& nums, int& duration) 
{
    auto start = std::chrono::high_resolution_clock::now();

    // Call the recursive merge sort function
    mergeSortRec(nums, 0, nums.size() - 1);

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return nums[nums.size() / 2];
}

void mergeSortRec(std::vector<int>& nums, size_t left, size_t right) 
{
    if (left < right) 
    {
        // Same as standard merge sort
        size_t mid = left + (right - left) / 2;

        // Recursive calls
        mergeSortRec(nums, left, mid);
        mergeSortRec(nums, mid + 1, right);

        // Merge the two halves in-place
        merge(nums, left, mid, right);
    }
}

void merge(std::vector<int>& nums, size_t left, size_t mid, size_t right) 
{
    // Create temporary vectors to hold the two halves
    std::vector<int> leftHalf(nums.begin() + left, nums.begin() + mid + 1);
    std::vector<int> rightHalf(nums.begin() + mid + 1, nums.begin() + right + 1);

    // Merge the two halves in-place
    std::vector<int>::iterator leftIter = leftHalf.begin();
    std::vector<int>::iterator rightIter = rightHalf.begin();
    std::vector<int>::iterator numsIter = nums.begin() + left;

    while (leftIter != leftHalf.end() && rightIter != rightHalf.end()) 
    {
        if (*leftIter <= *rightIter) 
        {
            *numsIter = *leftIter;
            ++leftIter;
        } 
        else 
        {
            *numsIter = *rightIter;
            ++rightIter;
        }

        ++numsIter;
    }

    // Copy the remaining elements of leftHalf and rightHalf if any
    std::copy(leftIter, leftHalf.end(), numsIter);
    std::copy(rightIter, rightHalf.end(), numsIter);
}