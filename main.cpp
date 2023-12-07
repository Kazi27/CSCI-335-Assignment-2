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
    
    //given inputs (input 1,2 and 3 size is 1000, input 4, 5 and 6 size is 31623, input 7, 8 and 7 size is 1000000)
    //std::ifstream inputFile("./input1.txt"); //50492874 all sorts work? 
    //std::ifstream inputFile("./input2.txt"); //19250688 all sorts work?
    //std::ifstream inputFile("./input3.txt"); //70244369 all sorts work?
    //std::ifstream inputFile("./input4.txt"); //50173306 but halfselect returns 83399603
    std::ifstream inputFile("./input5.txt"); //18637175 but halfselect returns 35469324
    //std::ifstream inputFile("./input6.txt"); //70984972 but halfselect returns 99445844
    //std::ifstream inputFile("./input7.txt"); //input too big for half select, 49971079, quickselect and median of medians takes too long?
    //std::ifstream inputFile("./input8.txt"); //input too big for half select, 18675104, quickselect and median of medians takes too long?
    //std::ifstream inputFile("./input9.txt"); //input too big for half select, 70722421, quickselect and median of medians takes too long?

    //own input
    //std::ifstream inputFile("./input10.txt"); 

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
    std::vector<int> OGvector1 = nums;
    std::vector<int> OGvector2 = nums;
    std::vector<int> OGvector3 = nums;
    std::vector<int> OGvector4 = nums;
    std::vector<int> OGvector5 = nums;
    std::vector<int> OGvector6 = nums;
    std::vector<int> OGvector7 = nums;
    std::vector<int> OGvector8 = nums;

    // Original Vector
    // std::cout << "The original vector to be sorted is ";
    // for (int num : nums) 
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << "\n";
    // std::cout << "\n";
    // std::cout << "\n";

    std::cout << "Number of elements in the vector: " << nums.size() << "\n";

    // std::vector<int> worstCaseInput = worstCaseQuickSelect();
    // std::vector<int> worstVect1 = worstCaseInput;
    // std::vector<int> worstVect2 = worstCaseInput;
    // std::vector<int> worstVect3 = worstCaseInput;
    // std::vector<int> worstVect4 = worstCaseInput;
    // std::vector<int> worstVect5 = worstCaseInput;
    // std::vector<int> worstVect6 = worstCaseInput; //all of this is to run worstcase vector of size 20k on the funcs, pass worstvvect as param
    // std::vector<int> worstVect7 = worstCaseInput;
    // std::vector<int> worstVect8 = worstCaseInput;

    // std::cout << "Original randomized worst case vector: ";
    // for (const auto& num : worstCaseInput) {
    //     std::cout << num << " ";
    // }
    // std::cout << "\n";
    // std::cout << "\n";
    // std::cout << "\n";

    // Run halfSelectionSort
    int halfSelectionSortMedian = halfSelectionSort(OGvector1, duration);

    if (halfSelectionSortMedian != -1) 
    {
        std::cout << "Median found by HalfSelectionSort: " << halfSelectionSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    // Run standardSort
    int standardSortMedian = standardSort(OGvector2, duration);

    if (standardSortMedian != -1) 
    {
        std::cout << "Median found by StandardSort: " << standardSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    // Run mergeSort
    int mergeSortMedian = mergeSort(OGvector3, duration);

    if (mergeSortMedian != -1) 
    {
        std::cout << "Median found by MergeSort: " << mergeSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    // Run inPlaceMergeSort
    int inPlaceMergeSortMedian = inPlaceMergeSort(OGvector4, duration);

    if (inPlaceMergeSortMedian != -1) 
    {
        std::cout << "Median found by InPlaceMergeSort: " << inPlaceMergeSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    // Run halfHeapSort
    int halfHeapSortMedian = halfHeapSort(OGvector5, duration);

    if (halfHeapSortMedian != -1)
    {
        std::cout << "Median found by HalfHeapSort: " << halfHeapSortMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    // Run quickSelect
    int quickSelectMedian = quickSelect(OGvector6, duration);

    if (quickSelectMedian != -1)
    {
        std::cout << "Median found by quickSelect: " << quickSelectMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    // Run quickSelect on worst-case input
    std::vector<int> worstCaseInput = worstCaseQuickSelect();
    // std::cout << "Original randomized worst case vector: ";
    // for (const auto& num : worstCaseInput) {
    //     std::cout << num << " ";
    // }
    // std::cout << "\n";
    // std::cout << "\n";
    // std::cout << "\n";
    int quickSelectWorstCaseMedian = quickSelect(worstCaseInput, duration);

    if (quickSelectWorstCaseMedian != -1) {
        std::cout << "Median found by quickSelect on worst-case input: " << quickSelectWorstCaseMedian << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    // Run medianOfMediansMethod
    std::vector<int> medianOfMediansInput = nums; // Copy the original vector for testing
    int medianOfMediansResult = medianOfMediansMethod(OGvector7, duration);

    if (medianOfMediansResult != -1) {
        std::cout << "Median found by Median of Medians: " << medianOfMediansResult << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    return 0;
}