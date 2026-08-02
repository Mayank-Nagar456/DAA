#  Growth of Functions using C and GNUplot

##  Description

This project is a solution to **Question 1** of the **Design and Analysis of Algorithms (DAA) Lab**.

The program computes the values of different mathematical growth functions for various values of **n**, stores the results in a text file (`growth.txt`), and automatically executes a GNUplot script (`growth.gnu`) to visualize the growth of the functions.


##  Objective

- Evaluate the growth of different mathematical functions.
- Compare their asymptotic growth graphically.
- Understand the behavior of various time complexity functions.

##  Project Structure

.
├── growth.c
├── growth.gnu
├── growth.txt        (Generated automatically)
└── README.md

##  Functions Plotted

The program plots the following functions:

- n log₂ n
- 12√n
- 1/n
- n^(log₂ n)
- 100n² + 6n
- n^0.51
- n² − 324
- 50√n
- 2n³
- 3ⁿ
- 2³² × n
- log₂ n

---

##  Requirements

- GCC Compiler (MinGW GCC)
- GNUplot
- Visual Studio Code (Recommended)
- C Standard Library
- `math.h`

---

## 🚀 Compilation

```bash
gcc growth.c -o growth -lm
```


## ▶️ Execution

### Windows

```bash
growth
```

### Linux

The program will:

1. Generate `growth.txt`.
2. Execute `growth.gnu`.
3. Display the graph automatically using GNUplot.


##  Graph Details

- **X-axis:** Value of `n`
- **Y-axis:** Function Value
- **Scale:** Logarithmic (Y-axis)

A logarithmic scale is used so that functions with widely different growth rates can be compared on the same graph.
##  Technologies Used

- C Programming
- GNUplot
- File Handling
- Mathematical Functions (`math.h`)

---

##  Concepts Covered

- Asymptotic Analysis
- Order of Growth
- Time Complexity
- Mathematical Function Evaluation
- Graph Plotting using GNUplot

##  Author

**Mayank**

B.Tech – Computer Engineering

Design and Analysis of Algorithms (DAA) Lab

## License

This project is created for educational and academic purposes.
