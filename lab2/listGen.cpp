#include <iostream>
#include <vector>
#include <cstdlib> // needed for both abs and rand

#include "listGen.h"

// for this lab, ima try not to use the namespace std
// using namespace std;

// notes from the lecture:
// ( <- represnts +1 ) <- represents -1   for this lab we don't the prefix sum to be negative
// we want to ask the user how many times to scramble the array and then do the check
    // std::cout << randList[2*n] << std::endl;
    // after the array is generated we scramble the array using the Fisher-Yates algorithm:
    // then finally we call the prefix sum to check if the array's prefix sum doesn't go bellow 0:

// generates the 2n array, first half is +1 while the second half is -1
std::vector<int> generateRandList(int n){
    std::vector<int> listOfOnes(2*n);

    // edge case - size too small
    if (n <= 0){
        std::cout << "Must enter a size greater than 0" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    for (int i=0; i<2*n; i++){
        if (i < n){
            listOfOnes[i] = 1;
        }else{
            listOfOnes[i] = -1;
        }
    }

    return listOfOnes;
}

// modifies the array by applying the fisher yates shuffle (randomly shuffle) from the last element to 0
void fisherYatesShuffle(std::vector<int>& arr) {

    for (int i = arr.size() - 1; i > 0; i--){
        // rand() returns a int from 1 to some big number we have to obtain a smaller number within the size of the array
        int randomIndex = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
    
}

// checks if the given list is balanced
// code modified from lab 1
bool isBalanced(const std::vector<int>& arr){
    int sum = 0;

    // iterate through the array and calc the prefix sum
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
        // prefix can't go below negative at any point
        if (sum < 0){
            return false;
        }
    }
    // checks if the array prefix sum is 0
    if (sum == 0){
        return true;
    }
    return false;
}

// as the name of the func implies, runs one single experiment; generate, shuffle, and check balance
bool runSingleExperiment(int n) {
    // generates a list of n +1s and n -1s
    std::vector<int> list = generateRandList(n);
    
    // randomly shuffle the list with the fisher yates algorithm
    fisherYatesShuffle(list);
    
    // check if the shuffled list is balanced with prefix sum
    return isBalanced(list);
}

// run multiple experiments and return proportion of balanced lists
double runExperiments(int n, int numTrials) {
    int balancedCount = 0;
    
    // run the experiment numTrials times
    for (int i = 0; i < numTrials; i++) {
        if (runSingleExperiment(n)) {
            balancedCount++;  // count successful balanced lists
        }
    }
    
    // return the ratio of balanced lists to total trials
    return (double)balancedCount / numTrials;
}