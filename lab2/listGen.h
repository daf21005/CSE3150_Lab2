#ifndef LISTGEN_H
#define LISTGEN_H

#include <vector>
#include <cstdlib> 

// generate a list of n +1s followed by n -1s
std::vector<int> generateRandList(int n);

// fisher-Yates shuffle algorithm
void fisherYatesShuffle(std::vector<int>& arr);

// check if list is balanced (non-negative prefix sums)
bool isBalanced(const std::vector<int>& arr);

// run experiment: generate, shuffle, check balance returns true if balanced, false otherwise
bool runSingleExperiment(int n);

// run multiple experiments and return proportion of balanced lists
double runExperiments(int n, int numTrials);


#endif