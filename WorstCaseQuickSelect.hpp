// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 2

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
// #ifndef WORSTQUICKSELECT_HPP
// #define WORSTQUICKSELECT_HPP //hpp stuff

// #include <iostream> //guards
// #include <vector>
// #include <algorithm>
// #include <chrono>
// #include <fstream>
// #include <iterator> //for shuffle
// #include <random> //for shuffle

// std::vector<int> worstCaseQuickSelect()
// {
//     std::vector<int> worstCaseInput(20000);

//     for (int i = 0; i < 10000; ++i)
//     {
//         worstCaseInput[i] = i + 1;
//         worstCaseInput[i + 10000] = 20000 - i;
//     }

//     return worstCaseInput;
// }
// #endif

// #include <vector>
// #include <algorithm>
// #include <chrono>

// std::vector<int> worstCaseQuickSelect()
// {
//     std::vector<int> worstCaseInput(20000);

//     for (int i = 0; i < 20000; ++i)
//     {
//         worstCaseInput[i] = 20000 - i;
//     }

//     return worstCaseInput;
// }
#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int>& worstCaseQuickSelect(){
    //such that the pivot we selected should always be 1 more than the smallest
    int size = 20000;
    int halfsize = (size)/2;
    static std::vector<int> worse(size);
    std::vector<int>::iterator start = worse.begin();
    std::vector<int>::iterator center = worse.begin() + halfsize;
    std::vector<int>::iterator end = worse.end() - 1;
    
  

    for(int i = 0; i < halfsize; ++i){
        if(i % 2 == 0){
            *(center + i) = i + 1;
        }else{
            *(center + i) = halfsize + i;
        }
        *(start + i) = (i + 1) * 2;
    }

    return worse;
}