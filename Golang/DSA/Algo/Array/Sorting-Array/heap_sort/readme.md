Complexity Breakdown

Time Complexity: $O(n log n)$ across best, average, and worst cases because building the initial heap takes $O(n)$ time, and extracting the elements one by one takes $O(log n)$ time per element for a total of n steps.

Space Complexity: $O(1)$ when implemented iteratively, or $O(log n)$ auxiliary stack space when using the recursive heapify strategy shown above due to the depth of the binary tree call stack frames.

Stable:- no