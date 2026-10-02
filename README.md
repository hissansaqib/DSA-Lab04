# Lab 04 - Singly Linked Lists

Hey, this is my submission for Lab 04. The lab covers the implementation of a singly linked list in C++ from scratch using dynamically allocated nodes and a custom `List` class. 

## Files Included
I separated the tasks into 6 different files as per the instructions:
* `Q1.cpp` - Basic creation and traversal (CreateThreeNodes and PrintList)
* `Q2.cpp` - Appending nodes using a loop and counting them
* `Q3.cpp` - Searching for a value and accessing the second node
* `Q4.cpp` - Inserting nodes at the beginning of the list
* `Q5.cpp` - Deleting specific nodes by value (handles first, middle, last, and missing cases)
* `Q6.cpp` - The final integrated menu-driven application

## How to run
Since every file has its own `main()` function, you need to compile and run them independently. You can use standard g++ commands. 

For example, to test the final menu application (Task 6):
```bash
g++ Q6.cpp -o task6
./task6