//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

int halfHeapSort(std::vector<int>& nums, int& duration)
{
    auto start_time = std::chrono::high_resolution_clock::now(); // start_time time of algo

    // Move the first element to the end
    nums.push_back(std::move(nums[0]));
    nums.erase(nums.begin());
    // std::swap(nums[0], nums[nums.size() - 1]);

    //partial heapsort to get bottom n/2 elements in ascending order
    buildHeap(nums);

    int size = nums.size(); 
    //int size = (nums.size() - 1) / 2; //exclude first element at index 0 //uncomment this to make small inpiut work

    // while (size > (nums.size() / 2 + 1))
    // {
    //     std::swap(nums[0], nums[size - 1]);
    //     size--;
    //     percDown(nums, 0, size);
    // }

    for (int i = size; i > (size / 2) + 1; --i)
    {
        std::swap(nums[0], nums[i - 1]);
        nums.pop_back();
        percDown(nums,0);
    }

    //nums.resize(nums.size() / 2 + 1);
    auto end_time = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    //median is at root of the remaining heap
    int median = nums[0];
    return median;
}

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole)
{
    int size = heap.size();
        int temp = std::move(heap[hole]);

        while (hole * 2 + 1 < size)
        {
            int child = hole * 2 + 1; //left child
            //selecting da larger child and if they are equal, chosoe the left child
            if (child != size - 1 && heap[child] > heap[child + 1])
            {
                child++; //right child if larger
            }

            if (heap[child] < temp)
            {
                heap[hole] = std::move(heap[child]);
                hole = child;
            }

            else
            {
                break;
            }
        }
        heap[hole] = std::move(temp);
}

void buildHeap(std::vector<int>& heap)
{
    int size = heap.size();
    for (int i = (size - 2) / 2; i >= 0; --i)
    {
        percDown(heap, i);
    }
}

#endif