#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"

int main() 
{
    std::vector<int> nums; //read input from file into vector
    int num;
    //std::ifstream inputFile("./input1.txt"); //given inputs
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

    return 0;
}