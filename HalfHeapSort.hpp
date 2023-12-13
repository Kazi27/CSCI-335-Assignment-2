// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 2

// #ifndef HALFHEAPSORT_HPP
// #define HALFHEAPSORT_HPP //hpp stuff

// #include <iostream> //guards
// #include <vector>
// #include <algorithm>
// #include <chrono>
// #include <fstream>

// // parameter "hole" is the index of the hole.
// // percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// // percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
// void percDown(std::vector<int>& heap, std::vector<int>::size_type hole)
// {
//     int leftChild;
//     int temp = heap[0];

//     for(; hole * 2 < heap.size(); hole = leftChild) {
//         leftChild = hole * 2;
//         if(leftChild + 1 < heap.size() && heap[leftChild] > heap[leftChild + 1]) {
//             leftChild++;
//         }   
//         if(temp > heap[leftChild]) {
//             heap[hole] = heap[leftChild];
//         }
//         else{
//             break;
//         }
//     }

//     heap[hole] = temp;
// }

// void buildHeap(std::vector<int>& heap)
// {
//     for(int i = (heap.size()-1)/2; i > 0; i--) {
//         heap[0] = heap[i];
//         percDown(heap, i);
//     }
// }

// int halfHeapSort(std::vector<int>& nums, int& duration)
// {
//     auto start_time = std::chrono::high_resolution_clock::now(); // start_time time of algo

//     // Move the first element to the end
//     // nums.push_back(std::move(nums[0]));
//     // nums.erase(nums.begin());
//     // std::swap(nums[0], nums[nums.size() - 1]);
//     nums.push_back(nums[0]);

//     //partial heapsort to get bottom n/2 elements in ascending order
//     buildHeap(nums);

//     //int size = nums.size(); 
//     //int size = (nums.size() - 1) / 2; //exclude first element at index 0 //uncomment this to make small inpiut work

//     // while (size > (nums.size() / 2 + 1))
//     // {
//     //     std::swap(nums[0], nums[size - 1]);
//     //     size--;
//     //     percDown(nums, 0, size);
//     // }
//     int middle = (nums.size()-2)/2;

//     for(int i = 0; i < middle; i++)
//     {
//         std::swap(nums[0], nums[i - 1]);
//         nums.pop_back();
//         percDown(nums,0);
//     }

//     //nums.resize(nums.size() / 2 + 1);
//     auto end_time = std::chrono::high_resolution_clock::now();

//     duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

//     //median is at root of the remaining heap
//     int median = nums[1];
//     return median;
// }

// #endif

//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2
#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) 
{
    int leftChild;
    int temp = heap[0];

    for(; hole * 2 < heap.size(); hole = leftChild) 
    {
        leftChild = hole * 2;
        if(leftChild + 1 < heap.size() && heap[leftChild] > heap[leftChild + 1]) 
        {
            leftChild++;
        }   

        if(temp > heap[leftChild]) 
        {
            heap[hole] = heap[leftChild];
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
    for(int i = (heap.size()-1)/2; i > 0; --i) 
    {
        heap[0] = heap[i];
        percDown(heap, i);
    }
}

int halfHeapSort(std::vector<int>& nums, int& duration) // func delcr
{
    auto start = std::chrono::steady_clock::now(); // start_time time of algo

    nums.push_back(nums[0]); //move first element to the end

    buildHeap(nums); //partial heapsort to get bottom n/2 elements in ascending order

    int middle = (nums.size()-2)/2;

    for(int i = 0; i < middle; i++) 
    {
        nums[0] = nums[nums.size() - 1];
        nums.pop_back();
        percDown(nums, 1);
    }

    auto end = std::chrono::steady_clock::now();

    duration = std::chrono::duration<double, std::milli> (end - start).count();

    return nums[1]; //median at nums[1] as per project specs
}