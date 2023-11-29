#include "WorstCaseQuickSelect.hpp"

std::vector<int> worstCaseQuickSelect() 
{ 
    static std::vector<int> worstCaseVector;
    
     if (worstCaseVector.empty()) 
     { 
        // Generate worst-case input for quickselect 
        for (int i = 1; i <= 20000; ++i) 
        { 
            worstCaseVector.push_back(i); 
        } 
    } 
            
    return worstCaseVector; 
}