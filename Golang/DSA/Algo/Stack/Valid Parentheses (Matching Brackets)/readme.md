
Time Complexity $O(n)$: 
- The algorithm iterates through the string of length $n$ exactly once. Each push, pop, and peek operation on the linked-list stack runs in constant time, $O(1)$.

Space Complexity $O(n)$: 
- In the worst-case scenario (e.g., a string consisting entirely of opening brackets like `(((({{{{`), all $n$ characters will be pushed onto the custom linked-list stack, requiring linear space proportional to the input size.

PROBLEM:-[leatcode](https://leetcode.com/problems/valid-parentheses/description/)