REVERSE_STACK

- Time Complexity: $\mathcal{O}(n)$, where $n$ is the number of elements in the stack. The function iterates through a single for loop that runs exactly $n$ times, popping each element from the original stack and pushing it into the auxiliary stack once.
- Space Complexity: $\mathcal{O}(n)$ because a brand-new auxiliary stack is allocated in memory to store all $n$ elements.
