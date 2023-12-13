// //Name: Kazi Sameen Anwar
// //CSCI - 335 Assignment 2

// #ifndef QUICKSELECT_HPP
// #define QUICKSELECT_HPP //hpp stuff

// #include <iostream> //guards
// #include <vector>
// #include <algorithm>
// #include <chrono>
// #include <fstream>

// int quickSelect (std::vector<int>& nums, int& duration)
// {
//      if (nums.empty())
//     {
//         return -1; 
//     }

//     int n = nums.size();
//     int k = n / 2; 

//     auto start = std::chrono::high_resolution_clock::now(); //start time of algo

//     if (n % 2 == 0) {
//         k = n / 2 - 1;
//                 // int mid1 = quickSelectHelper(nums, nums.begin(), nums.end() - 1, k - 1);
//          quickSelectHelper(nums, nums.begin(), nums.end() - 1, k);
//     } else {
//         k = n / 2;
//          quickSelectHelper(nums, nums.begin(), nums.end() - 1, k);
//     }

//     auto end = std::chrono::high_resolution_clock::now(); //yea we know

//     duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //kay

//     //print the sorted vector (for testing purposes, remove in the final version)
//     // std::cout << "Sorted vector by QuickSelect: ";
//     // for (int num : nums) 
//     // {
//     //     std::cout << num << " ";
//     // }
//     // std::cout << "\n";

//     //find & return median of the sorted vector
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

// // hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
// // hoarePartition returns an iterator to the pivot after it's placed.
// //Note that this implementation of hoarePartition makes it usable with different pivot selection methods, but also requires that you select your pivot and swap it into the last position prior to calling hoarePartition.
// std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
// {
//     // std::vector<int>::iterator pivot = choosePivot(nums, low, high); //returns pivot
//     // std::swap(*pivot, *(high - 1)); //pivot swapped with second to last element
//     // pivot = high - 1; 
    
//     // auto i = low; //moves right, looking for stuff smaller than the pivot
//     // auto j = high - 2; //moves left, looking for stuff bigger than the pivot
//     // while (true) 
//     // { 
//     //     while (*i < *pivot) 
//     //     {
//     //         ++i; //move right when smaller than pivot
//     //     }

//     //     while (*j > *pivot) 
//     //     {
//     //         --j; //move left when bigger than pivot
//     //     }

//     //     if (i < j) 
//     //     {
//     //         std::swap(*i, *j); //when they meet or cross swap
//     //     }
        
//     //     else 
//     //     {
//     //         break; 
//     //     }
//     // } 
    
//     // std::swap(*i, *pivot); 
//     // return i; //by the end u have a left part smaller than pivot, right part bigger than pivot
//     auto pivot = medianOfThree(low, low + std::distance(low, high) / 2, high);
//     std::iter_swap(pivot, high);
//     auto i = low;
//     auto j = high - 1;
//     while (true)
//     {
//         while (i < j && *i < *high)
//         {
//             i++;
//         }
//         while (j > i && *j >= *high)
//         {
//             j--;
//         }
//         if (i >= j)
//         {
//             break;
//         }
//         std::swap(*i, *j);
//     }
//     std::swap(*i, *high);
//     return i;
// }

// int quickSelectHelper(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int k)
// {
//     if (high - low < 10)
//     {
//         std::sort(low, high + 1); 
//         return *(low + k);
//     }
//     auto partition = hoarePartition(nums, low, high);
//     int pivotDist = std::distance(low, partition);

//     if (pivotDist == k)
//     {
//         return *partition;
//     }
//     else if (pivotDist > k)
//     {
//         return quickSelectHelper(nums, low, partition - 1, k);
//     }
//     else
//     {
//         return quickSelectHelper(nums, partition + 1, high, k - pivotDist - 1);
//     }
// }

// std::vector<int>::iterator medianOfThree(std::vector<int>::iterator first, std::vector<int>::iterator middle, std::vector<int>::iterator last)
// {
//     if (*first > *middle)
//     {
//         if (*first < *last) 
//             return first;
//         else if (*middle > *last) 
//             return middle;
//         else 
//             return last;
//     }
//     else
//     {
//         if (*first > *last) 
//             return first;
//         else if (*middle < *last) 
//             return middle;
//         else 
//             return last;
//     }
// }

// #endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

//return iterator at high, which will be the pivot
std::vector<int>::iterator medianof3 (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){

    std::vector<int>::iterator center = low;

    std::advance(center, std::distance(low, high) / 2);//moving iterator center to point to the middle value of the list

    //std::cout << "LOW: " << *low << ", CENTER: " << *center << ", HIGH: " << *high << ", ";
 
    if((*low == *center && *low == *high) || *low == *center || *low == *high){//if all 3 values are equal OR low and center are same value OR low and high has the same value

        std::iter_swap(low, high);   

    }else if(*center == *high){// if middle and right most has the same value
    
        std::iter_swap(center, high);

    }else{

        if((*low < *center && *center < *high) || (*high < *center && *center < *low )){

            std::iter_swap(center, high);//center should be the pivot

        }else if((*center < *low  && *low < *high) || (*high < *low && *low < *center)){

            std::iter_swap(low, high);//low should be the pivot

        }else{

            return high;//high should be the pivot
        }

    }

    return high;

}

std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){

    std::vector<int>::iterator pivot = medianof3(nums, low, high);// return the pivot iterator, which is at high - 1
    //std::cout << "Pivot: " << *pivot << "\n";
    std::vector<int>::iterator left = low;
    std::vector<int>::iterator right = pivot - 1; //high is the position of pivot, and high - 1 will be the right start of our partitioning
    //std::cout << "\n" <<"Pivot: " << *pivot << "\n";

    ///*
    while(true){
        while(left < pivot && *left < *pivot){
            ++left;
        }
        while(right > low && *right > *pivot){
            --right;
        }
        //std::cout << "Pivot: " << *pivot << " Left: " << *left << " Right: " << *right << "\n";
        if(left >= right){
            break;
        }
        std::iter_swap(left, right);
        ++left;
        --right;
        
    }
    //*/
    std::iter_swap(left, pivot);

    /*
    for(int i = 0; i < nums.size(); i++){
        std::cout  << nums[i] << ", ";
    }
    std::cout << std::endl;
    */
    /*

    
    //std::cout << "\n";
    for(auto i = low; i <= high; i++){
        std::cout  << *i << ", ";
    }
    std::cout << "\n";   
    */
    return left;    
    

    
}

void quickSelect (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator center){
    //!(low + 9 <= high)
    if(high <= low + 9){//if low + 9 is greater than or equals to high, meaning the range from low to high has less than or equal to 10 element
        std::sort(low, high + 1);
        //std::cout << "It stops here, at Sort" << "\n";
        return;
    }

    std::vector<int>::iterator median = hoarePartition(nums, low, high);

    if(median == center){
        //std::cout << "It stoppes here" << "\n";
        return;
    }else if (median < center){
        quickSelect(nums, median + 1, high, center);
    }else{
        quickSelect(nums, low, median - 1, center);
    }
}

int quickSelect (std::vector<int>& nums, int& duration){
    auto start = std::chrono::steady_clock::now();

    quickSelect(nums, nums.begin(), nums.end() - 1, nums.begin() + (nums.size() - 1)/2);

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return *(nums.begin() + (nums.size() - 1)/2);//returning the middle element as the pivot
}