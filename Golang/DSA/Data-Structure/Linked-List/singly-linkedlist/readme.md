Complexity Breakdown:<br>

Time Complexity: $O(n)$ for `length`, `deleteAtTail`, `deleteByValue`, `traverse`, `isExist`, `insertAtTail`, and `reverse` because these operations must traverse the nodes one by one up to the end of the list $(n nodes)$ in the worst case; whereas `insertAtHead` and `deleteAtHead` take $O(1)$ constant time as they only update immediate pointers at the root node without any traversal loops.

Space Complexity: $O(1)$ across all functions because every single operation modifies existing pointer connections in-place or uses a fixed number of temporary tracking variables (`current`, `prev`, `count`), requiring zero extra memory that scales with the size of the input list.

```
Note:you can optimise tail operations by keeping tail pointer. 

type LinkedList struct {
	head *Node
	tail *Node // Keeps track of the last node permanently
	size int   // Keeps track of the length dynamically
}

type Node struct {
	data int
	next *Node
}
``