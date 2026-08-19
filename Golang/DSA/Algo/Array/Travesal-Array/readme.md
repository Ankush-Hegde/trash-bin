1. Traditional for Loop and for range (Index Only)
- Time Complexity: $O(n)$
    - The loop visits each of the n elements exactly once.
- Space Complexity: $O(1)$ (Constant Space)
    - It only uses a single integer variable (```i``` or ```index```) for iteration, requiring no extra memory.

2. Standard for range (Value Copy)
- Time Complexity: $O(n)$
    - It visits every element once.
- Space Complexity: $O(1)$ or $O(m)$ per iteration, where m is the element size.
    - Go creates a temporary variable to hold a copy of the current element.
    - If the array contains huge, complex structs, copying them on every iteration creates overhead, though total auxiliary memory does not grow with n.

3. Pointer-Based ```for range``` (```range &array```)
- Time Complexity: $O(n)$
- Space Complexity: $O(1)$
    - By ranging over a pointer to the array, Go avoids copying large structs, making it the most memory-efficient choice for large data sets.