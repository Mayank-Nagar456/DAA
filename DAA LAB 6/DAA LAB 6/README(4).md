# DAA Lab-06 Solutions

## Overview

This repository contains C programs for all four questions of **DAA Lab-06**.

The programs are designed to validate the required algorithms and demonstrate their time complexity.

---

# Question 1: 1D Array Operations

Given an unsorted array of `n` integers, perform the following operations:

1. Find maximum element
2. Find first and second largest elements
3. Find mean
4. Find median
5. Find standard deviation
6. Find mode
7. Remove all duplicates
8. Reverse the array
9. Partition the array around a pivot

For partitioning, elements **greater than or equal to the pivot** are placed before elements **less than the pivot**.

## Algorithms and Complexity

| Operation | Time Complexity | Extra Space |
|---|---:|---:|
| Maximum | O(n) | O(1) |
| First and second largest | O(n) | O(1) |
| Mean | O(n) | O(1) |
| Median using sorting | O(n²) with Bubble Sort | O(n) |
| Standard deviation | O(n) | O(1) |
| Mode | O(n²) | O(1) |
| Remove duplicates | O(n²) | O(1) |
| Reverse | O(n) | O(1) |
| Partition | O(n) | O(n) |

### Important Note

The median function uses Bubble Sort to sort a copy of the array. Therefore, the complexity of the implemented median procedure is **O(n²)**.

## Program Structure

The program does not use a `do-while` menu or `switch-case`.

All operations are called directly from `main()`.

---

# Question 2: 2D Square Matrix Operations

For an `n × n` square matrix, perform:

1. Matrix addition
2. Matrix multiplication
3. Create a zero matrix
4. Check whether the matrix is symmetric
5. Find determinant
6. In-place transpose
7. Find dominant eigenvalue and corresponding eigenvector

## Algorithms and Complexity

| Operation | Time Complexity | Extra Space |
|---|---:|---:|
| Matrix Addition | O(n²) | O(n²) for result |
| Matrix Multiplication | O(n³) | O(n²) for result |
| Zero Matrix | O(n²) | O(n²) |
| Symmetric Matrix | O(n²) | O(1) |
| Determinant using Gaussian Elimination | O(n³) | O(n²) |
| In-place Transpose | O(n²) | O(1) |
| Eigenvalue/Eigenvector using Power Iteration | O(k n²) | O(n) |

Here, `k` is the number of power iterations.

### Important Note

The eigenvalue/eigenvector procedure implemented in the program uses **Power Iteration** and finds the **dominant eigenvalue and its corresponding eigenvector**. It does not compute all eigenvalues and eigenvectors.

The transpose is performed **in-place**, meaning no separate matrix is required.

## Program Structure

The program directly calls all seven matrix operations from `main()`.

There is no `do-while` menu and no `switch-case`.

---

# Question 3: Convolution of Two Vectors

Given two vectors:

- `A` of length `m`
- `B` of length `n`
- `n >= m`

The convolution is:

```text
C[k] = Σ A[j] × B[k-j]
```

The required algorithm should run in:

```text
O(n log n)
```

## Approach: Fast Fourier Transform (FFT)

The program uses FFT-based convolution.

### Steps

1. Find a power-of-two size `N` such that:

```text
N >= m + n - 1
```

2. Zero-pad both vectors to size `N`.

3. Compute FFT of `A`.

4. Compute FFT of `B`.

5. Multiply the transformed values point-by-point:

```text
FFT(C) = FFT(A) × FFT(B)
```

6. Apply inverse FFT.

7. The first `m + n - 1` values form the convolution result.

## Complexity

```text
FFT(A)       = O(N log N)
FFT(B)       = O(N log N)
Multiplication = O(N)
Inverse FFT  = O(N log N)
```

Therefore:

```text
Overall Time Complexity = O(n log n)
```

---

# Question 4: Sorting a Permutation Using Reversals

Given a permutation of:

```text
1, 2, 3, ..., n
```

the only allowed operation is:

```text
reverse(p, i, j)
```

which reverses the elements from position `i` to position `j`.

The task has two parts:

1. Show that every permutation can be sorted using `O(n)` reversals.
2. Design an algorithm with total reversal cost `O(n log² n)` when the cost of:

```text
reverse(p, i, j)
```

is:

```text
|j - i| + 1
```

## Part 1: O(n) Reversals

A simple strategy is to place the correct element at each position.

For position `i`:

1. Find the value `i`.
2. Reverse the segment needed to move it into position `i`.
3. Continue with the next position.

At most a constant number of reversals are required for each element, giving:

```text
O(n) reversals
```

However, the total cost of those reversals can be `O(n²)`.

## Part 2: O(n log² n) Cost

The advanced solution uses a divide-and-conquer strategy.

### Basic idea

1. Divide the permutation into two groups according to their values.
2. Partition the sequence so that the smaller-value group and larger-value group become separate.
3. Use reversals to rotate blocks when necessary.
4. Recursively sort the two groups.
5. Continue until every group contains one value.

The recursion has approximately:

```text
O(log n)
```

levels.

At each level, the partitioning work can be bounded by:

```text
O(n log n)
```

giving the target bound:

```text
O(n log² n)
```

## Correctness Idea

At every recursive step, the algorithm separates the values into the correct lower and upper value ranges.

Therefore:

- Elements in the lower range are eventually placed in the left part.
- Elements in the upper range are eventually placed in the right part.
- Recursion sorts each part.
- At the final level, every element is in its correct position.

Thus the complete permutation is sorted.

---

# Compilation

## Question 1

Because `math.h` is used, compile with:

```bash
gcc q1.c -o q1 -lm
```

Run:

```bash
./q1
```

## Question 2

Compile with:

```bash
gcc q2.c -o q2 -lm
```

Run:

```bash
./q2
```

## Question 3

Compile with:

```bash
gcc q3.c -o q3 -lm
```

Run:

```bash
./q3
```

## Question 4

Compile with:

```bash
gcc q4.c -o q4
```

Run:

```bash
./q4
```

---

# Summary of Complexities

| Question | Main Algorithm | Time Complexity |
|---|---|---:|
| Q1 | Array operations | O(n²) worst case for implemented set |
| Q2 | Matrix operations | O(n³) worst case |
| Q3 | FFT Convolution | O(n log n) |
| Q4 | Divide and Conquer Reversal Sorting | O(n log² n) reversal cost |

---

## Learning Points

These programs demonstrate:

- Linear array algorithms
- In-place array operations
- Searching and comparison techniques
- Sorting and duplicate removal
- Statistical calculations
- Matrix algorithms
- Gaussian elimination
- In-place matrix transpose
- Power iteration
- Divide-and-conquer
- Fast Fourier Transform
- Convolution
- Reversal-based sorting
- Time and space complexity analysis

