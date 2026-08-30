# DAA Lab 5

## Question 1: Find the Median Without Sorting the List

### Objective
Find the median of `N` numbers without completely sorting the list.

### Approach
Use **Quickselect**, which is based on the partition operation of Quick Sort.

1. Choose a pivot.
2. Partition the array so that elements smaller than or equal to the pivot are on the left and larger elements are on the right.
3. The pivot reaches the position it would have in a sorted array.
4. Compare the pivot position with the required median position.
5. Continue only on the required side of the array.

### Median Position
- If `N` is odd, median position (0-based index) is `N / 2`.
- If `N` is even, find the elements at indices `N/2 - 1` and `N/2`, then take their average.

### Complexity
- Average Time: `O(N)`
- Worst Time: `O(N²)`
- Space: `O(log N)` on average due to recursion

---

## Question 2: Find the Kth Smallest Element Without Sorting

### Objective
Find the `K`th smallest element in a list of `N` numbers without completely sorting the array.

### Approach
Use **Quickselect**.

1. Convert the required position to a 0-based index: `K - 1`.
2. Partition the array around a pivot.
3. If the pivot position is `K - 1`, the pivot is the answer.
4. If `K - 1` is smaller than the pivot position, search the left partition.
5. Otherwise, search the right partition.

### Key Idea
Quickselect does not recursively process both sides like Quick Sort. It searches only the side containing the required element.

### Complexity
- Average Time: `O(N)`
- Worst Time: `O(N²)`
- Space: `O(log N)` on average due to recursion

---

## Question 3: Implement Quick Sort for N Elements Stored in a File

### Objective
Take `N` elements, store them in a file, read them from the file, and sort them using **Quick Sort**.

### Algorithm
1. Take `N` and the array elements as input.
2. Store the elements in an input file.
3. Read the elements back from the file.
4. Select a pivot and partition the array.
5. Recursively apply Quick Sort to the left partition.
6. Recursively apply Quick Sort to the right partition.
7. Display the sorted array.
8. Store the sorted result in an output file.

### Quick Sort Partition
The partition operation places the pivot in its correct position and divides the array into:
- Left side: elements less than or equal to the pivot
- Right side: elements greater than the pivot

### Complexity
- Best Time: `O(N log N)`
- Average Time: `O(N log N)`
- Worst Time: `O(N²)`
- Average Space: `O(log N)` for recursion

---

## Question 4: Implement Heap Sort for N Elements Stored in a File

### Objective
Generate or take `N` elements, store them in a file, read them from the file, and sort them using **Heap Sort**.

### Approach
Use a **Max Heap**.

1. Read the elements.
2. Build a Max Heap.
3. The largest element is at the root.
4. Swap the root with the last element.
5. Reduce the heap size.
6. Apply `heapify()` to restore the Max Heap property.
7. Repeat until the entire array is sorted.

### Heap Array Formulas
For a node at index `i`:
- Left child: `2 * i + 1`
- Right child: `2 * i + 2`
- Parent: `(i - 1) / 2`

### Complexity
- Best Time: `O(N log N)`
- Average Time: `O(N log N)`
- Worst Time: `O(N log N)`
- Auxiliary Space: `O(log N)` for the recursive heapify implementation

---

## Summary

| Question | Problem | Main Algorithm |
|---|---|---|
| Q1 | Find median without sorting | Quickselect |
| Q2 | Find Kth smallest without sorting | Quickselect |
| Q3 | Sort elements stored in a file | Quick Sort |
| Q4 | Sort elements stored in a file | Heap Sort |

### Important Concept
- **Quickselect:** Finds only the required position and does not completely sort the array.
- **Quick Sort:** Recursively sorts both partitions.
- **Heap Sort:** Builds a heap and repeatedly places the largest element at the end.
