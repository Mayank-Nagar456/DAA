# Bubble Sort Comparison using C and GNUplot

## Description

This project is a solution to **Question 3** of the **Design and Analysis of Algorithms (DAA) Lab**.

The program compares the performance of two versions of the Bubble Sort algorithm:

- Normal Bubble Sort
- Optimized Bubble Sort

The program counts the number of comparisons performed by both algorithms for different input sizes, stores the results in a text file (`bubble.txt`), and automatically executes a GNUplot script (`bubble.gnu`) to visualize the comparison results.

## Objective

- Implement normal Bubble Sort.
- Implement optimized Bubble Sort using the swapped flag technique.
- Count the number of comparisons performed by both algorithms.
- Compare algorithm efficiency for different input sizes.
- Visualize the performance difference using GNUplot.


## Project Structure



─ bubble.c
─ bubble.gnu
─ bubble.txt (Generated automatically)
─ README.md



## Algorithm Details

### Normal Bubble Sort

In normal Bubble Sort:

- Each pass compares adjacent elements.
- It continues all passes even if the array is already sorted.
- Number of comparisons remains almost the same for all cases.

Time Complexity:


O(n²)

### Optimized Bubble Sort

The optimized version uses a `swapped` variable.

Working:

- If no swapping occurs during a complete pass, the array is already sorted.
- The algorithm stops early.

Best Case Complexity:


O(n)


Average and Worst Case:


O(n²)


## Program Working

The program performs the following steps:

1. Generates random numbers for different array sizes.
2. Creates two identical copies of the array.
3. Applies normal Bubble Sort on the first array.
4. Applies optimized Bubble Sort on the second array.
5. Counts comparisons performed by both algorithms.
6. Stores results in `bubble.txt`.
7. Executes GNUplot to display the comparison graph.

## Input Sizes Tested

The program tests arrays of size:


100
200
300
400
500
600
700
800
900
1000


## Output File

### bubble.txt

This file stores the comparison count.

Format:


Size Normal Optimized
100 4950 4950
200 19900 19900
...


The file is automatically generated after program execution.

## Requirements

Software required:

- GCC Compiler
- GNUplot
- Visual Studio Code (Recommended)

Libraries used:

- stdio.h
- stdlib.h
- time.h


## Compilation

Compile the program using:

```bash
gcc bubble.c -o bubble
