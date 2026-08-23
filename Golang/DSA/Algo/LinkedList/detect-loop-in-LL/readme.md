1. <b>Floyd’s Cycle-Finding Algorithm (Tortoise and Hare)</b><br>
This is the optimal and standard approach. It utilizes two pointers moving at different speeds to traverse the list simultaneously.
    - How it works: Initialize two pointers <b>(slow and fast)</b> at the head node. Move slow by one step and fast by two steps at each iteration. If there is a loop, the fast pointer will eventually wrap around and meet the slow pointer inside the loop. If fast reaches NULL, no loop exists.
    - Time Complexity: $O(N)$
    - Space Complexity:  $O(1)$ (Constant memory)

2. <b>Hashing / Visited Set Approach</b><br>
This is a straightforward, intuitive approach that uses an auxiliary data structure to remember previously seen nodes.
    - How it works: Traverse the linked list node by node. Insert the memory address (or node reference) into a hash set as you visit them. Before adding a node, check if it already exists in the set. If it does, a loop is detected.
    - Time Complexity: $O(N)$
    - Space Complexity: $O(N)$ (Requires extra storage for nodes)

3. Modifying the Node Structure (Visited Flag)<br>
If you are allowed to modify the definitions of the elements in the linked list, you can embed tracking flags directly into them.
    - How it works: Add a boolean attribute (e.g., is_visited = False) to the Node structure. As you traverse the list, check if the current node’s flag is True. If it is, a loop exists. Otherwise, flip the flag to True and move to the next node.
    - Time Complexity: $O(N)$
    - Space Complexity: $O(1)$ (If modifying existing nodes, though it adds a permanent structural overhead).

4. Pointer Disconnection / Destructive Modification<br>
This is a clever hack that detects loops by intentionally breaking down the list pointers as they are parsed.
    - How it works: Create a single dummy node (e.g., temp). Traverse the list, and for every node you visit, save its actual next pointer destination, change its next pointer to point to your temp node, and step forward. If you ever encounter a node whose next pointer already references temp, you have circled back into a loop.
    - Time Complexity: $O(N)$
    - Space Complexity: $O(1)$ <br>
    ```Note: This destroys the original structural integrity of the linked list.```

<b>Summary Comparison</b>

| Method | Time Complexity | Space Complexity | Modifies List Structure? |
|-----------|----------------|---------------|------------|
|Floyd's Tortoise & Hare | $O(N)$ | $O(1)$ | No |
| Hashing (Hash Set) | $O(N)$ | $O(N)$ | No |
Visited Flag | $O(N)$ | $O(1)$ | Yes (Schema modified) | 
| Pointer Modification | $O(N)$ | $O(1)$ | Yes (Destructive) |