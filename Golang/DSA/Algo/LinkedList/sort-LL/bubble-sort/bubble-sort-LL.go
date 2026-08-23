package main

import "fmt"

// Node represents a single element in the linked list
type Node struct {
	Val  int
	Next *Node
}

// LinkedList encapsulates the head node pointer
type LinkedList struct {
	Head *Node
}

// Insert adds a new node to the end of the list
func (ll *LinkedList) Insert(val int) {
	newNode := &Node{Val: val}
	if ll.Head == nil {
		ll.Head = newNode
		return
	}
	current := ll.Head
	for current.Next != nil {
		current = current.Next
	}
	current.Next = newNode
}

// BubbleSort sorts the linked list by swapping data values
func (ll *LinkedList) BubbleSort() {
	// If the list is empty or has only one element, it is already sorted
	if ll.Head == nil || ll.Head.Next == nil {
		return
	}

	var swapped bool
	var lastChecked *Node = nil

	for {
		swapped = false
		current := ll.Head

		// Traverse the list until reaching the already sorted portion
		for current.Next != lastChecked {
			if current.Val > current.Next.Val {
				// Swap the data of adjacent nodes
				current.Val, current.Next.Val = current.Next.Val, current.Val
				swapped = true
			}
			current = current.Next
		}

		// Optimization: The last checked node is now in its final position
		lastChecked = current

		// If no two elements were swapped by the inner loop, break
		if !swapped {
			break
		}
	}
}

// Print displays the list elements sequentially
func (ll *LinkedList) Print() {
	current := ll.Head
	for current != nil {
		fmt.Printf("%d -> ", current.Val)
		current = current.Next
	}
	fmt.Println("nil")
}

func main() {
	list := &LinkedList{}

	// Populate the list with unsorted data
	list.Insert(64)
	list.Insert(34)
	list.Insert(25)
	list.Insert(12)
	list.Insert(22)
	list.Insert(11)

	fmt.Print("Original List: ")
	list.Print()

	list.BubbleSort()

	fmt.Print("Sorted List:   ")
	list.Print()
}
