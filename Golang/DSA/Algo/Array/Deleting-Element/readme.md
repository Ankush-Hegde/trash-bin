<b>Complexity Breakdown:</b><br>
Time Complexity: $O(n)$ because deleting an element requires shifting all subsequent elements one position to the left to fill the gap. In the worst-case scenario (deleting the very first element), the algorithm must copy and shift $n-1$ elements.

Space Complexity: $O(1)$ auxiliary space because the operation is performed in-place. The `append` function reuses the memory backing the original slice without allocating a new temporary array, provided the slice has sufficient capacity.