Complexity Analysis

Time Complexity:
- Worst case: $O(n^2)$ when the elements are in reverse order, requiring maximum passes and comparisons through the list.
- Best case: $O(n)$ if the list is already sorted, because the optimization (swapped flag) detects this in a single pass and terminates early.

Space Complexity: $O(1)$ because the sorting is performed in-place by modifying node values without allocating extra data structures.