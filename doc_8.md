# Sorting Algorithms in C

## Overview
This program generates **N random integers** in the range **1 to 1000** and sorts them using a sorting algorithm chosen by the user.  
It also counts and displays the **number of comparisons and swaps/moves** performed during sorting.

## Features
- Random number generation at runtime
- User choice of sorting algorithm:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
- Displays array before and after sorting
- Counts comparisons and swaps (moves for Merge Sort)

## Input
- Number of elements `N`
- Choice of sorting algorithm (1–4)

## Output
- Unsorted array
- Sorted array
- Total comparisons
- Total swaps/moves

## Sorting Algorithms Used
- **Bubble Sort:** Repeatedly swaps adjacent elements if they are in wrong order
- **Selection Sort:** Selects the smallest element and places it in correct position
- **Insertion Sort:** Inserts each element into its proper position
- **Merge Sort:** Divides the array and merges sorted subarrays (uses moves instead of swaps)

## Complexity
| Algorithm       | Time Complexity |
|-----------------|-----------------|
| Bubble Sort     | O(n²)           |
| Selection Sort  | O(n²)           |
| Insertion Sort  | O(n²)           |
| Merge Sort      | O(n log n)      |
