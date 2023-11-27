#include "HalfHeapSort.hpp"

int halfHeapSort(std::vector<int>& nums, int& duration) //func delcr
{
    auto start = std::chrono::high_resolution_clock::now(); //start time of algo

    auto end = std::chrono::high_resolution_clock::now(); //yea we know

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //kay

    //print the sorted vector (for testing purposes, remove in the final version)
    std::cout << "Sorted vector by MergeSort: ";
    for (int num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

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

    //side note: we probably use the helper here because its recursive and we dont want to call the main function more than once because it prints statements and times clocks?
}

void percDown(std::vector<int>& heap, std::vector<int>::size_type hole)
{

}

void buildHeap(std::vector<int>& heap)
{

}