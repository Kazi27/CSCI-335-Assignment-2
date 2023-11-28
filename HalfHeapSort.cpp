#include "HalfHeapSort.hpp"

void percDown(std::vector<int>& heap, std::vector<int>::size_type hole)
{
    std::vector<int>::size_type child;
    int temp = std::move(heap[hole]); // Save the value to be inserted into the hole
    int end = heap.size();

    while (hole * 2 + 1 < end) 
    {
        child = hole * 2 + 1;

        // Compare left and right child, choose the larger one
        if (child + 1 < end && heap[child] < heap[child + 1]) 
        {
            ++child;
        }

        // Compare the larger child with the value to be inserted
        if (heap[child] > temp) 
        {
            heap[hole] = std::move(heap[child]);
        } 
        else 
        {
            break;
        }

        hole = child;
    }

    heap[hole] = std::move(temp); // Insert the value into the correct place
}

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void buildHeap(std::vector<int>& heap)
{
    int end = heap.size();
    for (std::vector<int>::size_type i = end / 2; i >= 1; --i) 
    {
        percDown(heap, i - 1);
    }
}

int halfHeapSort(std::vector<int>& nums, int& duration) //func delcr
{
    auto start = std::chrono::high_resolution_clock::now(); //start time of algo

    // Move the first element to the back
    std::swap(nums[1], nums[nums.size() - 1]);
    buildHeap(nums);

    for (std::vector<int>::size_type i = 1; i < nums.size() / 2; ++i) 
    {
        std::swap(nums[1], nums[nums.size() - 1 - i]);
        percDown(nums, 1); // Start with index 1
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

    //find & return median of the sorted vector
    //return nums[1]; //if u make this 0, u get the correct thing but like he wants it to start at 1
    // Return the median of the sorted vector
    // return (nums.size() % 2 == 0) ? (nums[nums.size() / 2] + nums[nums.size() / 2 + 1]) / 2 : nums[nums.size() / 2 + 1];
    return nums[nums.size()/2];

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