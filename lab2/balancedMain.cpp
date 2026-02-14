#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "listGen.h"

// for this lab ima try not to use namespace std
// using namespace std;

int main(){
    // an issue that was happening is that the rand func had a set seed . to resolve we bring in srand
    srand(time(nullptr));

    int n;
    int numTrials;

    std::cout << "Enter size of array: " << std::endl;
    std::cin >> n;

    std::cout << "Enter number of trials: " << std::endl;
    std::cin >> numTrials;

    double ratio = runExperiments(n, numTrials);

    std::cout << "Results: " << std::endl;
    std::cout << "Balanced: " << (int)(ratio * numTrials) << "/" << numTrials << std::endl;
    std::cout << "Ratio: " << ratio << " (" << (ratio * 100) << "%)" << std::endl;
    //std::cout << ratio << std::endl;

    

    return 0;
}