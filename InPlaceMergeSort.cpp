#include "InPlaceMergeSort.hpp"

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

int inPlaceMergeSort(std::vector<int>& nums, int& duration) //entry point
{
    auto start = std::chrono::high_resolution_clock::now(); //start clock

    mergeSortRec(nums, 0, nums.size() - 1); //inplace merge sort on whole vect

    auto end = std::chrono::high_resolution_clock::now(); //enc clock
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //calc duration

    //print sorted vector but remove in the final
    std::cout << "Sorted vector by InPlaceMergeSort: ";
    for (const auto& num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    //return the median, specs say its the lesser of the two middle elements IF ITS EVEN, if odd just return the middle one
    int size1 = nums.size(); //using size1 here because used size before
    if (size1 % 2 == 0) //for even-sized vectors
    {
        //return the lesser of the middle elements
        return std::min(nums[size1 / 2 - 1], nums[size1 / 2]);
    } 

    else 
    {
        //for odd-sized vectors, return middle element
        return nums[size1 / 2];
    }

    //side note: we probably use the helper here because its recursive and we dont want to call the main function more than once because it prints statements and times clocks?
}