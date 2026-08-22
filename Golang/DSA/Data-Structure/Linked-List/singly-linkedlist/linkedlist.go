package main

import "fmt"

type Node struct {
	data int
	next *Node
}

// --------------------------length() -> start --------------------------
func (n *Node) length() int {
	if n == nil {
		return 0
	}

	count := 1
	CurrentNode := n

	for CurrentNode.next != nil {
		count++
		CurrentNode = CurrentNode.next
	}

	return count
}

// --------------------------length() -> end --------------------------

// ---------------------deletion -> start -------------------------------
func (n *Node) deleteAtHead() *Node {
	if n == nil {
		return nil
	}

	fmt.Printf("deleting at head: %d\n", n.data)
	return n.next
}

func (n *Node) deleteAtTail() *Node {
	if n == nil {
		return nil
	}

	// If the list has only ONE node, deleting it leaves the list empty
	if n.next == nil {
		fmt.Printf("deleting at tail (single node): %d\n", n.data)
		return nil
	}

	CurrentNode := n
	var PreviousNode *Node
	for CurrentNode.next != nil {
		PreviousNode = CurrentNode
		CurrentNode = CurrentNode.next
	}
	fmt.Printf("deleting at tail: %d\n", CurrentNode.data)

	PreviousNode.next = nil // remoove the link to last node

	// no need to free the memory of the last node like CurrentNode= nil,
	// Go’s Garbage Collector periodically scans the heap,
	// notices that those unlinked nodes can no longer be reached by any active part of your program,
	//  and automatically reclaims their memory.

	return n
}

func (n *Node) deleteByValue(data int) *Node {
	if n == nil {
		return nil
	}

	if n.data == data {
		fmt.Printf("deleting by value: %d\n", n.data)
		return n.next
	}

	CurrentNode := n
	for CurrentNode.next != nil {
		if CurrentNode.next.data == data {
			fmt.Printf("deleting by value: %d\n", CurrentNode.next.data)
			CurrentNode.next = CurrentNode.next.next
			return n
		}
		CurrentNode = CurrentNode.next
	}

	fmt.Printf("value %d not found in the linked list\n", data)

	return n
}

// ---------------------deletion -> end -------------------------------

// ---------------------travesal -> start -------------------------------
// we can even traverse recursively by passing CurrentNode.next in arg,
//  but iterative is better for large linked list
func (n *Node) traverse() {
	CurrentNode := n
	for CurrentNode != nil {
		fmt.Printf("%d -> ", CurrentNode.data)
		CurrentNode = CurrentNode.next
	}
	fmt.Println("nil")
}

// ---------------------travesal -> end ------------------------------

//  ---------------------search -> start ---------------------
func (n *Node) isExist(data int) bool {
	CurrentNode := n
	for CurrentNode != nil {
		if CurrentNode.data == data {
			return true
		}
		CurrentNode = CurrentNode.next
	}
	return false
}

// ---------------------search -> end ---------------------

// ------------------------insertion -> start------------

func (n *Node) insertAtTail(data int) {
	fmt.Printf("inserting at tail: %d\n", data)
	CurrentNode := n

	for CurrentNode.next != nil {
		CurrentNode = CurrentNode.next
	}

	newNode := &Node{data: data, next: nil}
	CurrentNode.next = newNode
}

func (n *Node) insertAtHead(data int) *Node {
	fmt.Printf("inserting at head: %d\n", data)
	newHeadNode := &Node{data: data, next: n}
	return newHeadNode
}

// for sorted array we can implement, we need to remember the previous
// node and current node, and insert the new node in between.

// ---------------------------------insertion -> end---------------------------------

// ---------------------reverse -> start ---------------------
func (n *Node) reverse() *Node {
	var prev *Node = nil
	current := n

	for current != nil {
		nextTemp := current.next // Store the next node
		current.next = prev      // Reverse the current node's pointer
		prev = current           // Move prev one step forward
		current = nextTemp       // Move current one step forward
	}

	return prev // prev becomes the new head of the reversed list
}

// ---------------------reverse -> end ---------------------

func main() {
	LinkedList := &Node{data: 3}
	LinkedList.next = &Node{data: 2, next: nil}

	fmt.Printf("-------insertAtTail--------\n")
	// Insert a new node with data 1 at the tail of the linked list
	LinkedList.insertAtTail(1)

	fmt.Printf("-------travesing--------\n")
	LinkedList.traverse() // Output: 3 -> 2 -> 1 -> nil

	fmt.Printf("-------insertAtHead--------\n")
	// Insert a new node with data 0 at the head of the linked list
	// return changed pointer of head node, so that it updates the head of the linked list
	LinkedList = LinkedList.insertAtHead(4)

	fmt.Printf("-------travesing--------\n")
	LinkedList.traverse() // Output: 4 -> 3 -> 2 -> 1 -> nil

	fmt.Printf("-------searching--------\n")
	fmt.Printf("Searching for 2: %v\n", LinkedList.isExist(2)) // Output: true
	fmt.Printf("Searching for 5: %v\n", LinkedList.isExist(5)) // Output: false

	fmt.Printf("-------reversing--------\n")
	LinkedList = LinkedList.reverse()
	LinkedList.traverse() // Output: 1 -> 2 -> 3 -> 4 -> nil

	fmt.Printf("-------deletion--------\n")
	LinkedList = LinkedList.deleteByValue(2)
	LinkedList.traverse() // Output: 1 -> 3 -> 4 -> nil
	LinkedList = LinkedList.deleteAtTail()
	LinkedList = LinkedList.deleteAtHead()
	LinkedList.traverse() // Output: 3 -> nil

	LinkedListSize := LinkedList.length()
	fmt.Printf("Length of the linked list: %d\n", LinkedListSize) // Output: 1
}
