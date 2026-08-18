Complexity Breakdown

Time Complexity: $O(n \log n)$ on average because the array is partitioned into roughly equal halves recursively, but it degrades to $O(n²)$ in the worst case if a poor pivot choice consistently yields unbalanced partitions Quick Sort.

Space Complexity: $O(\log n)$ because the recursive call stack stores stack frames proportional to the maximum depth of the recursion tree Quicksort Space Complexity.

Note: ```slices.Sort(numbers)``` uses a variation of Quick Sort (specifically pdqsort or Pattern-Defeating QuickSort, which is an optimized hybrid of quicksort, insertion sort, and heapsort)

Stable:- no

![alt text](image.png)