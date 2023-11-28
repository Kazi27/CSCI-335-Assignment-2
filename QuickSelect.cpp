#include "QuickSelect.hpp"

std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{

}

int quickSelect (std::vector<int>& nums, int& duration) //func declr
{
    auto start = std::chrono::high_resolution_clock::now(); //start time of algo

    auto end = std::chrono::high_resolution_clock::now(); //yea we know

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //kay

    //print the sorted vector (for testing purposes, remove in the final version)
    std::cout << "Sorted vector by QuickSelect: ";
    for (int num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 1;
}