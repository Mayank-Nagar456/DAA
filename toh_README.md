# Tower of Hanoi using C and GNUplot

## Description

This project is a solution to **Question 4** of the **Design and Analysis of Algorithms (DAA) Lab**.

The program implements the **Tower of Hanoi** recursive algorithm and calculates the number of moves required to solve the problem for different numbers of disks. The results are stored in `toh.txt` and visualized using GNUplot.


## Objective

- Implement Tower of Hanoi using recursion.
- Count the total number of moves.
- Analyze the growth of recursive algorithms.
- Visualize the relationship between number of disks and moves using GNUplot.

## Project Structure


.
├── toh.c
├── toh.gnu
├── toh.txt (Generated automatically)
└── README.md


## Algorithm Details

Tower of Hanoi consists of three rods:

- Source rod
- Auxiliary rod
- Destination rod

Rules:

- Move only one disk at a time.
- A larger disk cannot be placed on a smaller disk.
- All disks must be moved from source to destination.

The number of moves required is:


Moves = 2ⁿ - 1


where `n` is the number of disks.

## Program Working

The program performs the following steps:

1. Opens `toh.txt` file.
2. Runs Tower of Hanoi for disks from 1 to 20.
3. Counts the total number of moves.
4. Stores disk number and moves in the file.
5. Executes GNUplot to display the graph.

## Requirements

- GCC Compiler
- GNUplot
- C Standard Library

## Compilation

Compile the program using:

```bash
gcc toh.c -o toh
