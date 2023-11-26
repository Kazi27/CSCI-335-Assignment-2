#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"

int main() 
{
    // Read input from file into vector
    std::vector<int> nums;
    int num;
    std::ifstream inputFile("./input1.txt");

    if (inputFile.is_open()) 
    {
        while (inputFile >> num) 
        {
            nums.push_back(num);
        }
        inputFile.close();
    } 
    else 
    {
        std::cerr << "Unable to open input file.\n";
        return 1;
    }

    int duration;

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

    return 0;
}