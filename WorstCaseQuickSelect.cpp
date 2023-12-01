#include "WorstCaseQuickSelect.hpp"

std::vector<int> worstCaseQuickSelect() 
{
    std::vector<int> worstCaseVector;
    // for (int i = 1; i <= 200; ++i) //tested with 200 elements but proff wants 20000
    // {
    //     worstCaseVector.push_back(i);
    // }
    for (int i = 1; i <= 20000; ++i) //proff wants 20000
    {
        worstCaseVector.push_back(i);
    }

    //shuffle the vector to make it worst-case
    std::mt19937 k; //copied form project 1
    k.seed(2028358904); //copied form project 1
    std::shuffle(worstCaseVector.begin(), worstCaseVector.end(), k); //copied form project 1

    return worstCaseVector;
}