package main

import "fmt"

type Node struct {
	data int
	next *Node
}

// LinkedList tracks both ends of the chain for O(1) performance
type LinkedList struct {
	head *Node
	tail *Node // Keeps track of the last node permanently
	size int   // Keeps track of the length dynamically
}

// --------------------------length() -> O(1) --------------------------
func (l *LinkedList) length() int {
	return l.size // Instantly returns the size without looping
}

// ---------------------traversal -> O(n) -------------------------------
func (l *LinkedList) traverse() {
	current := l.head
	for current != nil {
		fmt.Printf("%d -> ", current.data)
		current = current.next
	}
	fmt.Println("nil")
}

// ------------------------insertion -> O(1) ----------------------------
func (l *LinkedList) insertAtHead(data int) {
	fmt.Printf("inserting at head: %d\n", data)
	newNode := &Node{data: data, next: l.head}

	if l.head == nil { // If list was empty
		l.tail = newNode
	}
	l.head = newNode
	l.size++
}

func (l *LinkedList) insertAtTail(data int) {
	fmt.Printf("inserting at tail: %d\n", data)
	newNode := &Node{data: data, next: nil}

	if l.head == nil { // If list was empty
		l.head = newNode
		l.tail = newNode
		l.size++
		return
	}

	// Instant O(1) insertion using the tail pointer
	l.tail.next = newNode
	l.tail = newNode
	l.size++
}

// ---------------------deletion -> O(1) & O(n) -----------------------
func (l *LinkedList) deleteAtHead() {
	if l.head == nil {
		return
	}

	fmt.Printf("deleting at head: %d\n", l.head.data)
	l.head = l.head.next
	l.size--

	if l.head == nil { // If the list is now empty
		l.tail = nil
	}
}

// NOTE: Deleting a tail in a SINGLY linked list still requires O(n)
// because we must find the node BEFORE the tail to clear its .next pointer.
// To make tail deletion O(1), you must use a Doubly Linked List.
func (l *LinkedList) deleteAtTail() {
	if l.head == nil {
		return
	}

	if l.head.next == nil {
		fmt.Printf("deleting at tail (single node): %d\n", l.head.data)
		l.head = nil
		l.tail = nil
		l.size--
		return
	}

	current := l.head
	for current.next != l.tail { // Stop at the second-to-last node
		current = current.next
	}

	fmt.Printf("deleting at tail: %d\n", l.tail.data)
	current.next = nil
	l.tail = current // Update tail pointer to the second-to-last node
	l.size--
}

// ---------------------update -> O(n) -----------------------
// updateByValue searches for the target value and updates it to the newValue
func (l *LinkedList) updateByValue(target int, newValue int) {
	current := l.head

	for current != nil {
		if current.data == target {
			fmt.Printf("Updating element %d to %d\n", target, newValue)
			current.data = newValue
			return // Exit once the first matching element is updated
		}
		current = current.next
	}

	fmt.Printf("Element %d not found in the list\n", target)
}

func main() {
	list := &LinkedList{}

	fmt.Printf("-------insertAtTail--------\n")
	list.insertAtTail(3)
	list.insertAtTail(2)
	list.insertAtTail(1)

	fmt.Printf("-------traversing--------\n")
	list.traverse() // Output: 3 -> 2 -> 1 -> nil

	fmt.Printf("-------insertAtHead--------\n")
	list.insertAtHead(4)

	fmt.Printf("-------traversing--------\n")
	list.traverse() // Output: 4 -> 3 -> 2 -> 1 -> nil

	fmt.Printf("-------deletion--------\n")
	list.deleteAtTail()
	list.deleteAtHead()
	list.traverse() // Output: 3 -> 2 -> nil

	fmt.Printf("Length of the linked list: %d\n", list.length()) // Output: 2

	fmt.Printf("-------update--------\n")
	list.updateByValue(2, 5)
	list.traverse() // Output: 3 -> 5 -> nil
}
