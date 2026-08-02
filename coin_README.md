

# Coin Toss Simulation using C and GNUplot

## Description

This project is a solution to **Question 2** of the **Design and Analysis of Algorithms (DAA) Lab**.

The program simulates coin toss experiments using random number generation in C. It calculates the probability of getting heads for different numbers of tosses, stores the results in text files, and automatically executes GNUplot to visualize the convergence of probability.

The experiment demonstrates the behavior of:

- Fair Coin (Probability of Head = 0.5)
- Biased Coin (Probability of Head = 0.8)

---

## Objective

- Simulate coin toss experiments using random numbers.
- Calculate the probability of getting heads.
- Verify the probability behavior of a fair coin.
- Analyze biased coin probability.
- Understand probability convergence.
- Visualize experimental results using GNUplot.


## Project Structure


.
─ coin.c
─ coin.gnu
─ fair_coin.txt (Generated automatically)
─ biased_coin.txt (Generated automatically)
─ README.md



## Program Working

The program performs experiments for different numbers of tosses:


10
100
1000
10000
100000


For every experiment:

1. Generate random coin toss outcomes.
2. Count the number of heads.
3. Calculate the probability of heads.
4. Store the result in output files.
5. Plot the results using GNUplot.

Formula used:


Probability of Head = Number of Heads / Total Number of Tosses


## Simulation Details

### Fair Coin

A fair coin has equal chances of Head and Tail.


P(Head) = 0.5


As the number of tosses increases, the experimental probability approaches 0.5.


### Biased Coin

A biased coin has a higher probability of producing Head.

Example:


P(Head) = 0.8


The simulation generates Head approximately 80% of the time, and the graph approaches 0.8 for large numbers of tosses.


## Generated Files

### fair_coin.txt

Stores the probability values obtained from the fair coin experiment.

Example:


10 0.40
100 0.49
1000 0.503
10000 0.499


### biased_coin.txt

Stores the probability values obtained from the biased coin experiment.

Example:


10 0.80
100 0.79
1000 0.801
10000 0.799


## Requirements

Software required:

- GCC Compiler
- GNUplot
- Visual Studio Code 

Libraries used:

- stdio.h
- stdlib.h
- time.h

## Compilation

Compile the program using:

```bash
gcc coin.c -o coin
