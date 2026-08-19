Complexity Breakdown

Time Complexity:

- Worst-Case: $O(n)$ because inserting at the beginning (index 0) requires shifting all $n$ existing elements one position to the right.
- Average-Case: $O(n)$ because inserting in the middle requires shifting roughly $\lfloor\frac{n}{2}\rfloor$ elements, which simplifies asymptotically to linear time.
- Best-Case: $O(1)$ when inserting at the very end of the slice, as no elements need to be shifted.

Space Complexity: $O(1)$ auxiliary space because the elements are shifted in-place using a single loop variable. However, if the underlying slice lacks capacity, Go's append will allocate a new array of size $O(n)$ to copy the elements over