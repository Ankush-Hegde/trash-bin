Complexity Analysis

Time Complexity: $O$(n \log n)$ on average. If the list is already sorted and the first element is repeatedly picked as the pivot, the height of the recursion tree breaks down to $O$(n)$, leading to a worst-case performance of $O$(n^2)$.

Space Complexity: $O$(\log n)$ auxiliary space on average due to the recursive call stack. Since pointers are reassigned dynamically, no additional physical nodes or lists are allocated.