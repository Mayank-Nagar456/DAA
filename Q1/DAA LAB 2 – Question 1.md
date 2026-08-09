# DAA LAB 2 – Question 1

## Dictionary Operations Using Unsorted Array

### Aim

To implement the primary operations of a Dictionary ADT using an **unsorted array** and analyze their worst-case time complexities.

---

## Dictionary Operations

The following seven operations are implemented:

1. Search
2. Insert
3. Delete
4. Maximum
5. Minimum
6. Predecessor
7. Successor

---

## Data Structure

The dictionary is implemented using an **unsorted array**.

Example:

```text
10  40  20  50  30
```

The elements are not maintained in sorted order.

---

## Operations and Time Complexity

| Operation | Worst-Case Complexity |
|---|---|
| Search | O(n) |
| Insert | O(1) |
| Delete | O(n) |
| Maximum | O(n) |
| Minimum | O(n) |
| Predecessor | O(n) |
| Successor | O(n) |

---

## Explanation

### 1. Search

The array is unsorted, so the elements may need to be checked one by one.

**Time Complexity:** `O(n)`

### 2. Insert

A new element is inserted at the end of the array when space is available.

**Time Complexity:** `O(1)`

### 3. Delete

The element is first searched and then the remaining elements are shifted.

**Time Complexity:** `O(n)`

### 4. Maximum

All elements must be checked to find the largest element.

**Time Complexity:** `O(n)`

### 5. Minimum

All elements must be checked to find the smallest element.

**Time Complexity:** `O(n)`

### 6. Predecessor

The array is unsorted, so all elements may need to be checked to find the largest element smaller than the given key.

**Time Complexity:** `O(n)`

### 7. Successor

All elements may need to be checked to find the smallest element greater than the given key.

**Time Complexity:** `O(n)`

---

## Program Files

```text
Q1/
│
├── dictionary.c
├── unsorted_array.txt
├── unsorted_array.gnu
├── unsorted_array.png
└── README.md
```

---

## Gnuplot

The execution/order-of-growth data is stored in a `.txt` file.

The `.gnu` file reads the data and generates the graph.

Run Gnuplot using:

```bash
gnuplot unsorted_array.gnu
```

The graph will be generated as:

```text
unsorted_array.png
```

---

## Result

The order of growth of the seven Dictionary operations using an **unsorted array** is analyzed and plotted.

The operations have the following growth:

```text
Search       → O(n)
Insert       → O(1)
Delete       → O(n)
Maximum      → O(n)
Minimum      → O(n)
Predecessor  → O(n)
Successor    → O(n)
```

## Conclusion

The experiment shows that an **unsorted array** provides constant-time insertion when space is available, while most other Dictionary operations require linear time in the worst case.