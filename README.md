# CSE 3140 Lab 2 - Balanced Lists
In this lab we are creating 3 main parts:
- Given n size, generate a list size of 2n consisting of postive 1s in the first n and negative 1s in the second half
- After generating the list we then shuffle the list with Fisher-Yates alorithm
- Then finally calculating the prefix sum where at any point of calculating can't be below the negatives and the sum must be 0 to be balanced



## Compilation and Execution
Compile and run main program:
```
g++ listGen.cpp balancedMain.cpp -o mainProg
./mainProg
```

Compile and run unit test:
```
g++ listGen.cpp testBalance.cpp -o test_balance
./test_balance
```

### David Flores
