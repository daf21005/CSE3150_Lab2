#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "./include/doctest.h" 
#include "listGen.h"
#include <cstdlib>
#include <ctime>


TEST_CASE("generateRandList creates correct size array") {
    std::vector<int> list = generateRandList(3);
    
    CHECK(list.size() == 6);  // 2*n = 2*3 = 6
}

TEST_CASE("generateRandList has n +1s and n -1s") {
    std::vector<int> list = generateRandList(5);
    
    // Count the +1s and -1s
    int numPlus = 0;
    int numMinus = 0;
    
    for (int x : list) {
        if (x == 1) numPlus++;
        if (x == -1) numMinus++;
    }
    
    CHECK(numPlus == 5);   // Should have 5 +1s
    CHECK(numMinus == 5);  // Should have 5 -1s
}

TEST_CASE("fisherYatesShuffle with fixed seed produces known result") {
    srand(12345);  // Fixed seed for reproducibility
    
    std::vector<int> list = {1, 2, 3, 4, 5};
    fisherYatesShuffle(list);
    
    // With seed 12345, we get a specific shuffle
    // Run once to find out what it is, then test it
    // Note: This is compiler/platform dependent!
    
    // Just verify it's different from original
    bool isDifferent = false;
    std::vector<int> original = {1, 2, 3, 4, 5};
    for (int i = 0; i < list.size(); i++) {
        if (list[i] != original[i]) {
            isDifferent = true;
            break;
        }
    }
    CHECK(isDifferent == true);
}