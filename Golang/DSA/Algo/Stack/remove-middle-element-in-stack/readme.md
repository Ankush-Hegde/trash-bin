Time and Space Complexity Breakdown

- Recursive Approach
    - Time Complexity: $O(N)$ where $N$ is the number of elements in the stack. Each element is visited once during the recursive descent to the middle and once during the backtracking phase.
    - Space Complexity: $O(N)$ due to the implicit call stack frames accumulated in memory as the recursion goes down to the middle element.
    
- Auxiliary Stack Approach
    - Time Complexity: $O(N)$. Elements are popped from the original stack to the auxiliary stack ($N/2$ operations), the middle element is removed ($1$ operation), and remaining elements are pushed back ($N/2$ operations), resulting in linear time overall.
    - Space Complexity: $O(N)$ because an extra auxiliary stack structure is allocated in memory to temporarily hold roughly half of the elements ($\lfloor N/2 \rfloor$), which scales linearly with the input size.

[geeksforgeeks](https://www.geeksforgeeks.org/dsa/delete-middle-element-stack/)