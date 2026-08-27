
<b>Stack using Dynamic Array</b><br>

![alt text](stackUsingArray1.png)

<b>Stack using Fixed Array</b><br>
Complexity Breakdown<br>

`Push(data int)`
- Time Complexity: $O(1)$
- Space Complexity: $O(1)$
- Reason: Directly assigns the value to the index tracked by top in constant time without shifting or resizing.

`Pop()`
- Time Complexity: $O(1)$
- Space Complexity: $O(1)$
- Reason: Decrements the top index pointer instantly.

`Peek()`
- Time Complexity: $O(1)$
- Space Complexity: $O(1)$
- Reason: Direct index access via s.top.

`IsEmpty() / IsFull() / Size()`
- Time Complexity: $O(1)$
- Space Complexity: $O(1)$
- Reason: Basic arithmetic evaluation and comparisons on integer fields.

Overall Space Complexity: $O(n)$ where $n$ is the fixed capacity provided when initializing the stack array via make([]int, capacity).

![alt text](stackUsingArray2.png)