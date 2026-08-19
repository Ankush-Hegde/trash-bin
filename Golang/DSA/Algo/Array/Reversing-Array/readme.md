Complexity Breakdown:

Time Complexity: $O(n)$ across all cases (best, average, and worst) because the algorithm always iterates through exactly half of the array ($\lfloor\frac{n}{2}\rfloor$ steps) to swap elements, which scales linearly with the total number of elements $n$ regardless of their initial order.

Space Complexity: $O(1)$ because the algorithm reverses the slice completely in-place, modifying the original underlying array data directly without allocating any temporary auxiliary arrays or using extra memory.