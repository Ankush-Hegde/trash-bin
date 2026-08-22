Complexity Breakdown:<br>

Time Complexity: $O(1)$ for `length`, `insertAtHead`, `insertAtTail`, `deleteAtHead`, and `deleteAtTail` because the structural manager stores direct references to boundaries and the node's prev pointer allows immediate step-back deletion without linear loops; whereas `traverseForward`, `traverseBackward`, `isExist`, `updateByValue`, `deleteByValue`, and `reverse` require $O(n)$ time as they must step through the list sequentially up to n elements.

Space Complexity: $O(1)$ across all operations because pointer changes and array reversals are performed entirely in-place by swapping existing struct fields on the heap, consuming a constant volume of structural memory that does not grow with the dataset size.

```
NOTE:- doubly linked list takes more memory than singly linked list, since it stores both next and previous pointer
```

![alt text](image.png)