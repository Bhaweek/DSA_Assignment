# Min Heap and Max Heap Implementation in C

# 1. Introduction
This program demonstrates how to construct a **Min Heap** and a **Max Heap** from an unsorted array using array-based heap representation.

# 2. Data Structure Definition

-> Heap Representation
- The heap is represented using a **one-dimensional array**.
- For an element at index `i`:
  - Left child is at index `2i + 1`
  - Right child is at index `2i + 2`
- This representation avoids the need for pointers and simplifies implementation.

# 3. Function Descriptions
-> `swap(int *a, int *b)`
Swaps two integer values.  
Used during heapify operations.

->`minHeapify(int arr[], int n, int i)`
Ensures the **Min Heap property** at index `i`.
- Parent node is smaller than its children.
- Recursively adjusts the subtree if a violation occurs.

->`maxHeapify(int arr[], int n, int i)`
Ensures the **Max Heap property** at index `i`.
- Parent node is larger than its children.
- Recursively adjusts the subtree if a violation occurs.

-> `buildMinHeap(int arr[], int n)`
Constructs a Min Heap from an unsorted array.
- Starts heapifying from the last non-leaf node up to the root.

-> `buildMaxHeap(int arr[], int n)`
Constructs a Max Heap from an unsorted array.
- Uses the same logic as Min Heap but with opposite comparison.

-> `printArray(int arr[], int n)`
Displays the elements of the array.

# 4. Overview of `main()` Function
1. An unsorted array is defined.
2. Two copies of the array are created:
   - One for Min Heap
   - One for Max Heap
3. The original array is printed.
4. The Min Heap is built and displayed.
5. The Max Heap is built and displayed.

# 5. Sample Output

Original Array:
10 3 17 8 25 1

Min Heap:
1 3 10 8 25 17

Max Heap:
25 10 17 8 3 1
