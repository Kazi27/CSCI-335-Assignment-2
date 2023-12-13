// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 2
//MERGED THIS INTO HPP AS PER PROJECT SPECS  -- to test this file do make rebuild and uncomment this stuff

// #include "StandardSort.hpp"

// int standardSort(std::vector<int>& nums, int& duration) //func declr as per usual, prolly no need for commenting in future files
// {
//     auto start = std::chrono::high_resolution_clock::now(); //start time of algo like before too

//     std::sort(nums.begin(), nums.end()); //std::sort sorts vector in ascending order lmao

//     auto stop = std::chrono::high_resolution_clock::now(); //end time of algo

//     duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count(); //duration of the algo

//     //dont include this in the final version, but print sorted vector for testing
//     // std::cout << "Sorted vector by StandardSort: ";
//     // for (int num : nums) 
//     // {
//     //     std::cout << num << " ";
//     // }
//     // std::cout << "\n";

//     //calc median of sorted vect, specs say its the lesser of the two middle elements IF EVEN, if odd size just the middle
//     int size = nums.size();
//     if (size % 2 == 0) //for even-sized vectors
//     {
//         //return the lesser of the middle elements
//         return std::min(nums[size / 2 - 1], nums[size / 2]);
//     } 

//     else 
//     {
//         //for odd-sized vectors, return middle element
//         return nums[size / 2];
//     }
// }