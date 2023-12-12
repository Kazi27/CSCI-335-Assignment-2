//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#ifndef MERGESORT_HPP
#define MERGESORT_HPP //hpp stuff

#include <iostream> //guards
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

void mergeSortHelper(std::vector<int>& nums, int left, int right) //recursive helpa func for merge sort
{
    if (left < right) //base case where left index is less than right index cause if left index is greater than or equal to right...ur at the end?
    {
        int mid = left + (right - left) / 2; //middle index

        mergeSortHelper(nums, left, mid); //recursively sort left and right halves, left to mid and then mid+1 to right. 
        mergeSortHelper(nums, mid + 1, right); //split and call mergesort again and again till array size 1 i believe

        std::vector<int> temp(right - left + 1); //merge sorted halves using std::merge
        
        std::merge(nums.begin() + left, nums.begin() + mid + 1, nums.begin() + mid + 1, nums.begin() + right + 1, temp.begin());

        std::copy(temp.begin(), temp.end(), nums.begin() + left); //copy merged elements back to OG vector
    }
}

int mergeSort (std::vector<int>& nums, int& duration)
{
    auto start = std::chrono::high_resolution_clock::now(); //yak what this is

    mergeSortHelper(nums, 0, nums.size() - 1); //merge sort on whole vect

    auto end = std::chrono::high_resolution_clock::now(); //yea we know

    //duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //kay

    //print the sorted vector (for testing purposes, remove in the final version)
    // std::cout << "Sorted vector by MergeSort: ";
    // for (int num : nums) 
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << "\n";

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

#endif