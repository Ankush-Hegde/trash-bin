package main

import "fmt"

// Node represents a single element in the singly linked list.
type Node struct {
	Val  int
	Next *Node
}

// QuickSort sorts the linked list and returns the new head and tail pointers.
func QuickSort(head *Node) *Node {
	if head == nil || head.Next == nil {
		return head
	}

	var smallerHead, smallerTail *Node
	var greaterHead, greaterTail *Node

	pivot := head
	current := head.Next
	pivot.Next = nil // Isolate the pivot node

	// Partitioning step
	for current != nil {
		nextAlloc := current.Next
		current.Next = nil // Disconnect the node to process independently

		if current.Val < pivot.Val {
			if smallerHead == nil {
				smallerHead = current
				smallerTail = current
			} else {
				smallerTail.Next = current
				smallerTail = current
			}
		} else {
			if greaterHead == nil {
				greaterHead = current
				greaterTail = current
			} else {
				greaterTail.Next = current
				greaterTail = current
			}
		}
		current = nextAlloc
	}

	// Recursively sort sublists
	smallerHead = QuickSort(smallerHead)
	greaterHead = QuickSort(greaterHead)

	// Connect smaller list -> pivot -> greater list
	if smallerHead != nil {
		// Find tail of the sorted smaller list
		temp := smallerHead
		for temp.Next != nil {
			temp = temp.Next
		}
		temp.Next = pivot
		head = smallerHead
	} else {
		head = pivot
	}

	pivot.Next = greaterHead

	return head
}

// Helper functions to test the code
func printList(head *Node) {
	for head != nil {
		fmt.Printf("%d -> ", head.Val)
		head = head.Next
	}
	fmt.Println("nil")
}

func main() {
	// Create unsorted list: 4 -> 1 -> 3 -> 2 -> 5
	head := &Node{Val: 4, Next: &Node{Val: 1, Next: &Node{Val: 3, Next: &Node{Val: 2, Next: &Node{Val: 5}}}}}

	fmt.Print("Original list: ")
	printList(head)

	head = QuickSort(head)

	fmt.Print("Sorted list:   ")
	printList(head)
}
