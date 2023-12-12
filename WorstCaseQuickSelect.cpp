// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 2

// #include "WorstCaseQuickSelect.hpp"

// std::vector<int> worstCaseQuickSelect() 
// {
//     std::vector<int> worstCaseVector;
//     for (int i = 0; i <= 12; ++i) //tested with small number of elements but proff wants 20000
//     {
//         worstCaseVector.push_back(i);
//     }
//     // for (int i = 0; i <= 20000; ++i) //proff wants 20000 //idk if if i starts at 1 or 0
//     // {
//     //     worstCaseVector.push_back(i);
//     // }

//     //shuffle the vector to make it worst-case
//     std::mt19937 k; //copied form project 1
//     k.seed(2028358904); //copied form project 1
//     std::shuffle(worstCaseVector.begin(), worstCaseVector.end(), k); //copied form project 1
//     //the seed produces a random vector with shuffled elements from 1 - 20k yeah but its the same vector each time like its not uniquely random lolz so idk
//     return worstCaseVector;
// }