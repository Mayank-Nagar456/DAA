# Checking Duplicate Elements in Array using C

## Description

This project is a solution to **Question 6** of the **Design and Analysis of Algorithms (DAA) Lab**.

The program checks whether a given set of `n` random numbers contains any duplicate elements. It compares each element with the remaining elements and determines whether duplicate values exist in the array.

## Objective

- Check uniqueness of elements in an array.
- Detect duplicate values using comparison technique.
- Understand the working of nested loops.
- Analyze the time complexity of the algorithm.

## Project Structure


.
├── duplicate.c
└── README.md


## Algorithm Details

The algorithm uses a simple comparison method:

1. Take `n` elements as input.
2. Compare each element with all elements after it.
3. If any two elements are equal, a duplicate is found.
4. Otherwise, all elements are unique.

Example:

Input:


10 20 30 40 20


Output:


Duplicate Found


## Program Working

The program performs the following steps:

1. Accepts the number of elements.
2. Stores array values.
3. Uses two nested loops to compare pairs of elements.
4. Sets a duplicate flag if matching values are found.
5. Displays the result.

## Requirements

- GCC Compiler
- C Standard Library

## Compilation

Compile the program using:

```bash
gcc duplicate.c -o duplicate
