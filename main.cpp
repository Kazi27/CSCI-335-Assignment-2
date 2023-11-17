#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "HalfSelectionSort.hpp"

int main() 
{
    // Read input from file into vector
    std::vector<int> nums;
    int num;
    std::ifstream inputFile("input.txt");

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
    int median = halfSelectionSort(nums, duration);

    if (median != -1) 
    {
        std::cout << "Median found by HalfSelectionSort: " << median << "\n";
        std::cout << "Time taken: " << duration << " milliseconds.\n";
    }

    return 0;
}