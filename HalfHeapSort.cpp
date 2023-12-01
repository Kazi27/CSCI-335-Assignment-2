//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#include "HalfHeapSort.hpp"

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown(std::vector<int>& heap, int hole, int size) 
{
    int temp = heap[hole];

    while (hole * 2 + 1 < size) 
    {
        int child = hole * 2 + 1; // Left child
        // Selecting the larger child. If they are equal, left child is chosen.
        if (child != size - 1 && heap[child] < heap[child + 1]) 
        {
            child++; // Right child if larger
        }

        if (heap[child] > temp) 
        {
            heap[hole] = heap[child];
            hole = child;
        } 
        
        else 
        {
            break;
        }
    }
    heap[hole] = temp;
}

void buildHeap(std::vector<int>& heap) 
{
    int size = heap.size();
    for (int i = (size - 2) / 2; i >= 0; --i) 
    {
        percDown(heap, i, size);
    }
}

int halfHeapSort(std::vector<int>& nums, int& duration) //func delcr
{
    auto start = std::chrono::high_resolution_clock::now(); //start time of algo

    // Move the first element to the end
    nums.push_back(nums[0]);
    nums.erase(nums.begin());

    buildHeap(nums);

    int size = nums.size();
    // Removing elements until half of the original size
    while (size > (nums.size() / 2)) {
        std::swap(nums[0], nums[size - 1]);
        size--;
        percDown(nums, 0, size);
    }

    auto end = std::chrono::high_resolution_clock::now(); //yea we know

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //kay

    //print the sorted vector (for testing purposes, remove in the final version)
    std::cout << "Sorted vector by HalfHeapSort: ";
    for (int num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return nums[0]; //return median

    //find & return median of the sorted vector
    //return nums[1]; //if u make this 0, u get the correct thing but like he wants it to start at 1
    // Return the median of the sorted vector
    // return (nums.size() % 2 == 0) ? (nums[nums.size() / 2] + nums[nums.size() / 2 + 1]) / 2 : nums[nums.size() / 2 + 1];
    //return nums[nums.size()/2];
    // int size = nums.size();
    // if (size % 2 == 0) //for even-sized vectors
    // {
    //     //return the maximum of the middle elements
    //     return std::max(nums[size / 2 - 1], nums[size / 2]);
    // } 
    // else 
    // {
    //     //for odd-sized vectors, return middle element
    //     return nums[size / 2];
    // }
    //side note: we probably use the helper here because its recursive and we dont want to call the main function more than once because it prints statements and times clocks?
}