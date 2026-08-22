package main

import "fmt"

// Node represents a doubly linked list node
type Node struct {
	data int
	next *Node
	prev *Node // Pointer to the previous node
}

// DoublyLinkedList manages the structural boundaries and size
type DoublyLinkedList struct {
	head *Node
	tail *Node
	size int
}

// --------------------------length() -> O(1) --------------------------
func (l *DoublyLinkedList) length() int {
	return l.size
}

// ---------------------traversal -> O(n) -------------------------------
func (l *DoublyLinkedList) traverseForward() {
	current := l.head
	fmt.Print("Forward: ")
	for current != nil {
		fmt.Printf("%d <-> ", current.data)
		current = current.next
	}
	fmt.Println("nil")
}

func (l *DoublyLinkedList) traverseBackward() {
	current := l.tail
	fmt.Print("Backward: ")
	for current != nil {
		fmt.Printf("%d <-> ", current.data)
		current = current.prev
	}
	fmt.Println("nil")
}

//  ---------------------search & update -> O(n) ---------------------
func (l *DoublyLinkedList) isExist(data int) bool {
	current := l.head
	for current != nil {
		if current.data == data {
			return true
		}
		current = current.next
	}
	return false
}

func (l *DoublyLinkedList) updateByValue(target int, newValue int) {
	current := l.head
	for current != nil {
		if current.data == target {
			fmt.Printf("Updating element %d to %d\n", target, newValue)
			current.data = newValue
			return
		}
		current = current.next
	}
	fmt.Printf("Element %d not found\n", target)
}

// ------------------------insertion -> O(1) ----------------------------
func (l *DoublyLinkedList) insertAtHead(data int) {
	fmt.Printf("inserting at head: %d\n", data)
	newNode := &Node{data: data, next: l.head, prev: nil}

	if l.head == nil {
		l.tail = newNode
	} else {
		l.head.prev = newNode
	}
	l.head = newNode
	l.size++
}

func (l *DoublyLinkedList) insertAtTail(data int) {
	fmt.Printf("inserting at tail: %d\n", data)
	newNode := &Node{data: data, next: nil, prev: l.tail}

	if l.tail == nil {
		l.head = newNode
	} else {
		l.tail.next = newNode
	}
	l.tail = newNode
	l.size++
}

// ---------------------deletion -> O(1) & O(n) -----------------------
// no need to return *node because head pointer is already updated in DoublyLinkedList struct
func (l *DoublyLinkedList) deleteAtHead() {
	if l.head == nil {
		return
	}

	fmt.Printf("deleting at head: %d\n", l.head.data)
	l.head = l.head.next
	l.size--

	if l.head == nil {
		l.tail = nil // List is now empty
	} else {
		l.head.prev = nil // Detach link to old head
	}
}

// OPTIMIZED: This is now O(1) because we can jump back using the prev pointer!
func (l *DoublyLinkedList) deleteAtTail() {
	if l.tail == nil {
		return
	}

	fmt.Printf("deleting at tail: %d\n", l.tail.data)
	l.tail = l.tail.prev
	l.size--

	if l.tail == nil {
		l.head = nil // List is now empty
	} else {
		l.tail.next = nil // Detach link to old tail
	}
}

func (l *DoublyLinkedList) deleteByValue(data int) {
	if l.head == nil {
		return
	}

	current := l.head
	for current != nil {
		if current.data == data {
			fmt.Printf("deleting by value: %d\n", data)

			// If it's the head node
			if current == l.head {
				l.deleteAtHead()
				return
			}
			// If it's the tail node
			if current == l.tail {
				l.deleteAtTail()
				return
			}

			// If it's a middle node, bridge the gap
			current.prev.next = current.next
			current.next.prev = current.prev
			l.size--
			return
		}
		current = current.next
	}
	fmt.Printf("Value %d not found for deletion\n", data)
}

// ---------------------reverse -> O(n) ---------------------
func (l *DoublyLinkedList) reverse() {
	current := l.head
	var temp *Node = nil

	// Swap next and prev pointers for all nodes
	for current != nil {
		temp = current.prev
		current.prev = current.next
		current.next = temp
		current = current.prev // Move to next node (which is now in current.prev)
	}

	// Update head and tail references
	if temp != nil {
		l.tail = l.head
		l.head = temp.prev
	}
}

func main() {
	list := &DoublyLinkedList{}

	fmt.Printf("-------insertAtTail & Head--------\n")
	list.insertAtTail(2)
	list.insertAtTail(3)
	list.insertAtHead(1)

	list.traverseForward()  // Output: 1 <-> 2 <-> 3 <-> nil
	list.traverseBackward() // Output: 3 <-> 2 <-> 1 <-> nil

	fmt.Printf("-------updating element--------\n")
	list.updateByValue(3, 4) // Change 3 to 4
	list.traverseForward()   // Output: 1 <-> 2 <-> 4 <-> nil

	fmt.Printf("-------reversing--------\n")
	list.reverse()
	list.traverseForward() // Output: 4 <-> 2 <-> 1 <-> nil

	fmt.Printf("-------deletion--------\n")
	list.deleteAtTail()    // Drops 1 (O(1) time!)
	list.deleteByValue(2)  // Drops 2
	list.traverseForward() // Output: 4 <-> nil

	fmt.Printf("Final Length: %d\n", list.length()) // Output: 1
}
