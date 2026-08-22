package main

import "fmt"

type CSLLNode struct {
	data int
	next *CSLLNode
}

type CircularSinglyLinkedList struct {
	head *CSLLNode
	tail *CSLLNode
	size int
}

// --------------------------length() -> O(1) --------------------------
func (l *CircularSinglyLinkedList) length() int {
	return l.size
}

// ---------------------traversal -> O(n) -------------------------------
func (l *CircularSinglyLinkedList) traverse() {
	if l.head == nil {
		fmt.Println("Empty List")
		return
	}
	current := l.head
	for {
		fmt.Printf("%d -> ", current.data)
		current = current.next
		if current == l.head {
			break
		}
	}
	fmt.Println("(head)")
}

//  ---------------------search & update -> O(n) ---------------------
func (l *CircularSinglyLinkedList) isExist(data int) bool {
	if l.head == nil {
		return false
	}
	current := l.head
	for {
		if current.data == data {
			return true
		}
		current = current.next
		if current == l.head {
			break
		}
	}
	return false
}

func (l *CircularSinglyLinkedList) updateByValue(target int, newValue int) {
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
func (l *CircularSinglyLinkedList) insertAtHead(data int) {
	fmt.Printf("inserting at head: %d\n", data)
	newNode := &CSLLNode{data: data}

	if l.head == nil {
		l.head = newNode
		l.tail = newNode
		newNode.next = newNode
	} else {
		newNode.next = l.head
		l.head = newNode
		l.tail.next = l.head // Complete the circle
	}
	l.size++
}

func (l *CircularSinglyLinkedList) insertAtTail(data int) {
	fmt.Printf("inserting at tail: %d\n", data)
	newNode := &CSLLNode{data: data}

	if l.head == nil {
		l.head = newNode
		l.tail = newNode
		newNode.next = newNode
	} else {
		newNode.next = l.head
		l.tail.next = newNode
		l.tail = newNode // Move tail to new node
	}
	l.size++
}

// ---------------------deletion -> O(1) & O(n) -----------------------
func (l *CircularSinglyLinkedList) deleteAtHead() {
	if l.head == nil {
		return
	}
	fmt.Printf("deleting at head: %d\n", l.head.data)
	if l.head == l.tail {
		l.head = nil
		l.tail = nil
	} else {
		l.head = l.head.next
		l.tail.next = l.head // Complete the circle
	}
	l.size--
}

func (l *CircularSinglyLinkedList) deleteAtTail() {
	if l.head == nil {
		return
	}
	fmt.Printf("deleting at tail: %d\n", l.tail.data)
	if l.head == l.tail {
		l.head = nil
		l.tail = nil
	} else {
		current := l.head
		for current.next != l.tail { // O(n) scan to get previous node
			current = current.next
		}
		current.next = l.head
		l.tail = current
	}
	l.size--
}

// ---------------------reverse -> O(n) ---------------------
func (l *CircularSinglyLinkedList) reverse() {
	if l.head == nil || l.head == l.tail {
		return
	}
	var prev *CSLLNode = nil
	current := l.head
	nextTemp := l.head
	oldHead := l.head

	for {
		nextTemp = current.next
		current.next = prev
		prev = current
		current = nextTemp
		if current == l.head {
			break
		}
	}
	l.tail = oldHead
	l.head = prev
	l.tail.next = l.head
}

func main() {
	fmt.Println("=== 1. INITIALIZING LIST ===")
	csll := &CircularSinglyLinkedList{}

	// Test: length on empty list
	fmt.Printf("Initial size: %d\n", csll.length())
	csll.traverse()

	fmt.Println("\n=== 2. TESTING INSERTIONS ===")
	csll.insertAtTail(20)
	csll.insertAtTail(30)
	csll.insertAtHead(10)
	csll.insertAtTail(40)

	// Test: traverse and length after items added
	fmt.Print("Current List: ")
	csll.traverse()
	fmt.Printf("Current size: %d\n", csll.length())

	fmt.Println("\n=== 3. TESTING SEARCH (isExist) ===")
	// Test: searching for items that exist and items that don't
	fmt.Printf("Does 30 exist? %t\n", csll.isExist(30))
	fmt.Printf("Does 99 exist? %t\n", csll.isExist(99))

	fmt.Println("\n=== 4. TESTING UPDATE (updateByValue) ===")
	// Test: updating a valid value
	csll.updateByValue(30, 35)
	fmt.Print("List after update: ")
	csll.traverse()

	// Test: updating an invalid value
	csll.updateByValue(99, 100)

	fmt.Println("\n=== 5. TESTING REVERSAL ===")
	fmt.Print("Before reverse: ")
	csll.traverse()
	csll.reverse()
	fmt.Print("After reverse:  ")
	csll.traverse()

	fmt.Println("\n=== 6. TESTING DELETIONS ===")
	// Test: delete from head
	csll.deleteAtHead()
	fmt.Print("List after deleteAtHead: ")
	csll.traverse()

	// Test: delete from tail
	csll.deleteAtTail()
	fmt.Print("List after deleteAtTail: ")
	csll.traverse()

	fmt.Printf("Final size: %d\n", csll.length())
}
