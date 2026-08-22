package main

import "fmt"

type CDLLNode struct {
	data int
	next *CDLLNode
	prev *CDLLNode
}

type CircularDoublyLinkedList struct {
	head *CDLLNode
	tail *CDLLNode
	size int
}

// --------------------------length() -> O(1) --------------------------
func (l *CircularDoublyLinkedList) length() int {
	return l.size
}

// ---------------------traversal -> O(n) -------------------------------
func (l *CircularDoublyLinkedList) traverseForward() {
	if l.head == nil {
		fmt.Println("Forward: Empty List")
		return
	}
	current := l.head
	fmt.Print("Forward: ")
	for {
		fmt.Printf("%d <-> ", current.data)
		current = current.next
		if current == l.head {
			break
		}
	}
	fmt.Println("(head)")
}

//  ---------------------search & update -> O(n) ---------------------
func (l *CircularDoublyLinkedList) updateByValue(target int, newValue int) {
	if l.head == nil {
		return
	}
	current := l.head
	for {
		if current.data == target {
			fmt.Printf("Updating element %d to %d\n", target, newValue)
			current.data = newValue
			return
		}
		current = current.next
		if current == l.head {
			break
		}
	}
	fmt.Printf("Element %d not found\n", target)
}

// ------------------------insertion -> O(1) ----------------------------
func (l *CircularDoublyLinkedList) insertAtHead(data int) {
	fmt.Printf("inserting at head: %d\n", data)
	newNode := &CDLLNode{data: data}

	if l.head == nil {
		l.head = newNode
		l.tail = newNode
		newNode.next = newNode
		newNode.prev = newNode
	} else {
		newNode.next = l.head
		newNode.prev = l.tail
		l.head.prev = newNode
		l.tail.next = newNode
		l.head = newNode
	}
	l.size++
}

func (l *CircularDoublyLinkedList) insertAtTail(data int) {
	fmt.Printf("inserting at tail: %d\n", data)
	newNode := &CDLLNode{data: data}

	if l.head == nil {
		l.head = newNode
		l.tail = newNode
		newNode.next = newNode
		newNode.prev = newNode
	} else {
		newNode.next = l.head
		newNode.prev = l.tail
		l.tail.next = newNode
		l.head.prev = newNode
		l.tail = newNode
	}
	l.size++
}

// ---------------------deletion -> O(1) -----------------------
func (l *CircularDoublyLinkedList) deleteAtHead() {
	if l.head == nil {
		return
	}
	fmt.Printf("deleting at head: %d\n", l.head.data)
	if l.head == l.tail {
		l.head = nil
		l.tail = nil
	} else {
		l.head = l.head.next
		l.head.prev = l.tail
		l.tail.next = l.head
	}
	l.size--
}

func (l *CircularDoublyLinkedList) deleteAtTail() {
	if l.tail == nil {
		return
	}
	fmt.Printf("deleting at tail: %d\n", l.tail.data)
	if l.head == l.tail {
		l.head = nil
		l.tail = nil
	} else {
		l.tail = l.tail.prev
		l.tail.next = l.head
		l.head.prev = l.tail
	}
	l.size--
}

// ---------------------reverse -> O(n) ---------------------
func (l *CircularDoublyLinkedList) reverse() {
	if l.head == nil || l.head == l.tail {
		return
	}
	current := l.head
	var temp *CDLLNode = nil
	for {
		temp = current.prev
		current.prev = current.next
		current.next = temp
		current = current.prev // Move forward (using reversed prev pointer)
		if current == l.head {
			break
		}
	}
	temp = l.head
	l.head = l.tail
	l.tail = temp
}

// --------------------- Execution Framework ---------------------
func main() {
	fmt.Println("\n=== 2. CIRCULAR DOUBLY LINKED LIST ===")
	cdll := &CircularDoublyLinkedList{}

	// --- 1. Test Initial Empty State ---
	fmt.Printf("Initial Size: %d\n", cdll.length()) // Uses length()
	cdll.traverseForward()

	// --- 2. Test Insertions ---
	cdll.insertAtTail(20)
	cdll.insertAtTail(30)
	cdll.insertAtHead(10)
	fmt.Printf("Current Size: %d\n", cdll.length()) // Uses length()
	cdll.traverseForward()

	// --- 3. Test Search & Update (Success & Failure paths) ---
	cdll.updateByValue(20, 25)
	cdll.updateByValue(99, 100) // Uses updateByValue missing error path
	cdll.traverseForward()

	// --- 4. Test Reverse ---
	cdll.reverse()
	cdll.traverseForward()

	// --- 5. Test Deletion at Tail ---
	cdll.deleteAtTail()
	cdll.traverseForward()

	// --- 6. Test Deletion at Head ---
	cdll.deleteAtHead() // Uses deleteAtHead()
	cdll.traverseForward()
	fmt.Printf("Final Size: %d\n", cdll.length()) // Uses length()
}
