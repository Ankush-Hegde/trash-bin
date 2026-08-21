package main

import "fmt"

type Node struct {
	data int
	next *Node
}

// insertion -> insertInSortedList()

// deletion -> deleteAtHead() , deleteAtTail(), deleteByValue()

// travesal -> traverse()

// search -> searchData()

// update, sorte, reverse

// insertAtTail()
func (n *Node) append(data int) {
	CurrentNode := n

	for CurrentNode.next != nil {
		CurrentNode = CurrentNode.next
	}

	newNode := &Node{data: data, next: nil}
	CurrentNode.next = newNode
}

// insertAtHead()
func (n *Node) insertAtHead(data int) *Node {
	newHeadNode := &Node{data: data, next: n}
	return newHeadNode
}

func main() {
	LinkedList := &Node{data: 3}
	LinkedList.next = &Node{data: 2, next: nil}

	fmt.Printf("-------append--------\n")
	// Append a new node with data 3 to the linked list
	LinkedList.append(1)

	fmt.Printf("LinkedList.data: %d \n", LinkedList.data)           // Output: 3
	fmt.Printf("LinkedList.next.data: %d \n", LinkedList.next.data) // Output: 2

	fmt.Printf("-------insertAtHead--------\n")
	// Insert a new node with data 0 at the head of the linked list
	// return changed pointer of head node, so that it updates the head of the linked list
	LinkedList = LinkedList.insertAtHead(4)

	fmt.Printf("LinkedList.data: %d \n", LinkedList.data)                     // Output: 4
	fmt.Printf("LinkedList.next.data: %d \n", LinkedList.next.data)           // Output: 3
	fmt.Printf("LinkedList.next.next.data: %d \n", LinkedList.next.next.data) // Output: 2
}
