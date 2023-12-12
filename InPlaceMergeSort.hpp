//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

int inPlaceMergeSort (std::vector<int>& nums, int& duration)
{
    auto start = std::chrono::high_resolution_clock::now(); //start clock

    mergeSortRec(nums, 0, nums.size() - 1); //inplace merge sort on whole vect

    auto end = std::chrono::high_resolution_clock::now(); //enc clock
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //calc duration

    //print sorted vector but remove in the final
    // std::cout << "Sorted vector by InPlaceMergeSort: ";
    // for (const auto& num : nums) 
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << "\n";

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
void merge(std::vector<int>& nums, size_t left, size_t mid, size_t right)
{
    std::vector<int> leftHalf(nums.begin() + left, nums.begin() + mid + 1); //temp vect to hold the left half
    std::vector<int> rightHalf(nums.begin() + mid + 1, nums.begin() + right + 1); //temp vect to hold the right half

    std::vector<int>::iterator leftIter = leftHalf.begin(); //initialize iterators
    std::vector<int>::iterator rightIter = rightHalf.begin(); 
    std::vector<int>::iterator numsIter = nums.begin() + left;

    while (leftIter != leftHalf.end() && rightIter != rightHalf.end()) //as long as you're not at the end yet for either iterator,
    {
        if (*leftIter <= *rightIter) //if ur current element in the left half is <= to curr element in the right half
        {
            *numsIter = *leftIter; //copy element from left half to the original vector
            ++leftIter; //then move to the next element in the left half
        } 

        else //this means the right iter >= left iter so
        {
            *numsIter = *rightIter; //first copy element from right half to the OG vector
            ++rightIter; //now move to the next element in the right half
        }

        ++numsIter; //when ur here just move to the next position in the OG vector
    }

    std::copy(leftIter, leftHalf.end(), numsIter); //copy remainin elements of each half if any
    std::copy(rightIter, rightHalf.end(), numsIter);
}

void mergeSortRec(std::vector<int>& nums, size_t left, size_t right)
{
    if (left < right) 
    {
        size_t mid = left + (right - left) / 2; //middle index

        mergeSortRec(nums, left, mid); //recursively sort left and right halves, left to mid and then mid+1 to right. 
        mergeSortRec(nums, mid + 1, right); //split and call mergesort again and again till array size 1 i believe

        merge(nums, left, mid, right); //merge the two halves in-place
    }
}

#endif