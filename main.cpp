//Name: Kazi Sameen Anwar
//CSCI - 335 Assignment 2

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iterator> //for shuffle in worst case
#include <random> //for shuffle in worst case
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"
#include "MedianOfMediansMethod.hpp"

int main() 
{
    std::vector<int> nums; //read input from file into vector
    int num;
    //std::ifstream inputFile("./input1.txt"); //given inputs
    //std::ifstream inputFile("./input4.txt");
    //std::ifstream inputFile("./input6.txt");
    std::ifstream inputFile("./input10.txt"); //own input

    if (inputFile.is_open()) //if the files open
    {
        while (inputFile >> num) //reads integers one by one
        {
            nums.push_back(num); //push each integer into the vector one by one
        }
        inputFile.close(); //close the file after u finish reading
    } 
    
    else //files closed so
    {
        std::cerr << "Unable to open input file.\n"; //no bueno
        return 1;
    }

    int duration;

    // Original Vector
    std::cout << "The original vector to be sorted is ";
    for (int num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Run halfSelectionSort
    int halfSelectionSortMedian = halfSelectionSort(nums, duration);

    if (halfSelectionSortMedian != -1) 
    {
        std::cout << "Median found by HalfSelectionSort: " << halfSelectionSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

    // Run standardSort
    int standardSortMedian = standardSort(nums, duration);

    if (standardSortMedian != -1) 
    {
        std::cout << "Median found by StandardSort: " << standardSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

    // Run mergeSort
    int mergeSortMedian = mergeSort(nums, duration);

    if (mergeSortMedian != -1) 
    {
        std::cout << "Median found by MergeSort: " << mergeSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

     // Run inPlaceMergeSort
    int inPlaceMergeSortMedian = inPlaceMergeSort(nums, duration);

    if (inPlaceMergeSortMedian != -1) 
    {
        std::cout << "Median found by InPlaceMergeSort: " << inPlaceMergeSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

    // Run halfHeapSort
    int halfHeapSortMedian = halfHeapSort(nums, duration);

    if (halfHeapSortMedian != -1)
    {
        std::cout << "Median found by HalfHeapSort: " << halfHeapSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

    // Run quickSelect
    int quickSelectMedian = quickSelect(nums, duration);

    if (quickSelectMedian != -1)
    {
        std::cout << "Median found by quickSelect: " << quickSelectMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

    // Run quickSelect on worst-case input
    std::vector<int> worstCaseInput = worstCaseQuickSelect();
    std::cout << "Original randomized worst case vector: ";
    for (const auto& num : worstCaseInput) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    int quickSelectWorstCaseMedian = quickSelect(worstCaseInput, duration);

    if (quickSelectWorstCaseMedian != -1) {
        std::cout << "Median found by quickSelect on worst-case input: " << quickSelectWorstCaseMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

    // Run medianOfMediansMethod
    //std::vector<int> medianOfMediansInput = nums; // Copy the original vector for testing
    int medianOfMediansResult = medianOfMediansMethod(nums, duration);

    if (medianOfMediansResult != -1) {
        std::cout << "Median found by Median of Medians: " << medianOfMediansResult << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

    return 0;
}