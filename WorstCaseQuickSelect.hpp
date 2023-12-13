// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 2
//this is the working version giving me points, below is another version, cpp file contains pervious versions I tested before autograder was up
//relaized we dont gotta make it uniquely random...

#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int>& worstCaseQuickSelect()
{
    int size = 20000;
    int half = (size)/2;
    static std::vector<int> worstInput(size);
    std::vector<int>::iterator start = worstInput.begin();
    std::vector<int>::iterator mid = worstInput.begin() + half; //proj says to use iterators
    std::vector<int>::iterator end = worstInput.end() - 1;
    
    for(int j = 0; j < half; ++j)
    {
        if(j % 2 == 0) //if its even
        {
            *(mid + j) = j + 1; //value at the middle + j position -> j + 1
        }
        
        else //odd
        {
            *(mid + j) = half + j; //value at middle + j position -> half + j
        }

        *(start + j) = (j + 1) * 2; //start val -> (j + 1) * 2
    }

    return worstInput;
}

//OLD VERSION
// #ifndef WORSTQUICKSELECT_HPP
// #define WORSTQUICKSELECT_HPP //hpp stuff

// #include <iostream> //guards
// #include <vector>
// #include <algorithm>
// #include <chrono>
// #include <fstream>
// #include <iterator> //for shuffle
// #include <random> //for shuffle

// //worstCaseQuickSelect generates a worst-case input for a quickselect that uses median-of-3 partitioning. The input it generates must be of length 20,000, and contain each number from 1-20000 once.
// std::vector<int> worstCaseQuickSelect()
// {
//     // std::vector<int> worstCaseVector;
//     // for (int i = 0; i <= 12; ++i) //tested with small number of elements but proff wants 20000
//     // {
//     //     worstCaseVector.push_back(i);
//     // }
//     // // for (int i = 0; i <= 20000; ++i) //proff wants 20000 //idk if if i starts at 1 or 0
//     // // {
//     // //     worstCaseVector.push_back(i);
//     // // }

//     // //shuffle the vector to make it worst-case
//     // std::mt19937 k; //copied form project 1
//     // k.seed(2028358904); //copied form project 1
//     // std::shuffle(worstCaseVector.begin(), worstCaseVector.end(), k); //copied form project 1
//     // //the seed produces a random vector with shuffled elements from 1 - 20k yeah but its the same vector each time like its not uniquely random lolz so idk
//     // return worstCaseVector;
//     std::vector<int> worstCaseInput(20000);

//     for (int i = 0; i < 20000; ++i)
//     {
//         worstCaseInput[i] = 20000 - i;
//     }

//     return worstCaseInput;
// }

// #endif