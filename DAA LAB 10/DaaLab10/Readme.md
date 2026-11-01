# DAA Lab 10 – Disjoint Set Union (DSU)

## 📌 About the Lab

This lab focuses on solving graph-related problems using the **Disjoint Set Union (DSU)** data structure.

DSU is used to manage groups of connected elements efficiently. It supports two main operations:

- **Find:** Finds the representative (parent) of a set.
- **Union:** Combines two different sets into one.

The programs are implemented in **C language**.

---

## 📝 List of Problems

### Q1. Online Graph Bipartiteness Testing

**Concepts Used:** Disjoint Set Union, Parity, Graph Theory

**Description:**
Checks whether a graph remains bipartite when edges are added one by one. The DSU structure with parity helps determine whether two connected vertices belong to different groups.

**Time Complexity:** O(α(V)) per operation, where α is the inverse Ackermann function.

---

### Q2. Dynamic Connected Components in a Grid

**Concepts Used:** DSU, 2D Grid, Connected Components

**Description:**
Calculates the number of islands after each land cell is added to a grid. Each newly added land cell is connected with its neighbouring land cells.

**Time Complexity:** Approximately O(α(m × n)) per addition, with four neighbour checks.

---

### Q3. Maximum Weight Component with Size Constraints

**Concepts Used:** DSU, Component Size, Component Sum

**Description:**
Combines connected components and maintains their total weight and size. The program finds the maximum component weight while considering the given size constraints.

**Time Complexity:** O(E α(V) + V) for the implementation that scans all vertices after processing edges.

---

### Q4. Reverse Time-Step DSU Application

**Concepts Used:** DSU, Reverse Processing, Connected Components

**Description:**
Processes vertex deletion operations in reverse order. Instead of directly handling deletions, the program activates vertices and joins them with their active neighbours.

**Time Complexity:** O(VE + E α(V)) for the straightforward edge-scanning implementation.

---

### Q5. Lexicographically Smallest Connected Component Permutation

**Concepts Used:** DSU, Sorting, Connected Components

**Description:**
Groups indices that belong to the same connected component. The values inside each component are sorted and assigned to their corresponding indices to obtain the lexicographically smallest possible permutation.

**Time Complexity:** O((V + E) α(V) + V log V).

---

## 🛠️ Technologies Used

- Programming Language: C
- Compiler: GCC
- Concepts: Data Structures and Algorithms
- Topic: Graph Algorithms and Disjoint Set Union

---

## ▶️ How to Run the Programs

### Step 1: Compile the C program

```bash
gcc q1.c -o q1
```

### Step 2: Execute the program

```bash
./q1
```

For Windows:

```bash
gcc q1.c -o q1.exe
q1.exe
```

Repeat the same steps for `q2.c`, `q3.c`, `q4.c`, and `q5.c`.

---

## 📂 Project Structure

```text
DAA-Lab-10/
│
├── q1.c
├── q2.c
├── q3.c
├── q4.c
├── q5.c
│
└── README.md
```

---

## 🎯 Learning Outcomes

After completing this lab, I learned:

- How the Disjoint Set Union data structure works.
- How to implement Find and Union operations.
- How Path Compression improves performance.
- How Union by Size helps combine components efficiently.
- How DSU can be applied to graph and grid problems.
- How to use DSU for dynamic connectivity and component-based problems.
- How to solve graph problems using different algorithmic approaches.

---

## 👨‍💻 Conclusion

This lab helped me understand the practical applications of **Disjoint Set Union (DSU)** in graph algorithms. By solving these five problems, I gained experience in handling connected components, graph connectivity, grid-based problems, and efficient set operations using C.