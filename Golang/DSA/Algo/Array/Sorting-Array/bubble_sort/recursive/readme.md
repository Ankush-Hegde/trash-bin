Complexity Breakdown

Time Complexity: $O(n^2)$ 
- Worst Case: $O(n^2)$
    - Occurs when the array is sorted in reverse order. The algorithm performs \(n - 1\) passes, executing a diminishing number of comparisons (\(n-1, n-2, \dots, 1\)) on each recursive layer.
    - Average Case: $O(n^2)$ Randomly distributed elements require roughly $\lfloor\frac{n(n-1)}{4}\rfloor$ swaps and comparisons.
    - Best Case: $O(n)$ Thanks to the swapped flag optimization, if the array is already sorted, the loop runs exactly once $(n-1 comparisons)$ and returns early before making further recursive calls.

Space Complexity: $O(n)$ 
- Auxiliary Space: $(O(n)$ 
    - Unlike the iterative version which uses constant $O(1)$ space, the recursive approach introduces call stack overhead.
    - In the worst case, the function calls itself $n$ times before reaching the base case, pushing $n$ activation records onto the system stack.

![alt text](../image.png)