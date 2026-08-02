# Finding Partition Point in Binary Array using C

## Description

This project is a solution to **Question 5** of the **Design and Analysis of Algorithms (DAA) Lab**.

The program finds the **partition point** in an array containing a sequence of `0`s followed by a sequence of `1`s.

The partition point is the index where the transition occurs from `0` to `1`, i.e., the position of the first `1` in the array. The program uses **Binary Search** to find this point efficiently.

## Objective

- Find the transition point between 0s and 1s.
- Implement Binary Search for a sorted binary array.
- Reduce searching time compared to linear search.
- Analyze the efficiency of the algorithm.

## Project Structure


.
├── partition.c
└── README.md


## Algorithm Details

The array contains:


0 0 0 0 1 1 1 1


The first `1` is called the partition point.

Example:


Index: 0 1 2 3 4 5 6
Array: 0 0 0 0 1 1 1

Partition Point = 4


The algorithm uses Binary Search:

- If middle element is `1`, store the position and search left for an earlier `1`.
- If middle element is `0`, search the right half.
- Continue until the first `1` is found.

## Program Working

The program performs:

1. Takes the size of the array as input.
2. Accepts elements containing 0s followed by 1s.
3. Applies Binary Search.
4. Returns the index of the first `1`.
5. Prints the partition point.


## Requirements

- GCC Compiler
- C Standard Library


## Compilation

Compile the program using:

```bash
gcc partition.c -o partition
