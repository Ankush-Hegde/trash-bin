package main

import "fmt"

// Node represents a single element in the linked list
type Node struct {
	Val  int
	Next *Node
}

// IterativeMergeSort sorts the linked list bottom-up with O(1) space
func IterativeMergeSort(head *Node) *Node {
	if head == nil || head.Next == nil {
		return head
	}

	// 1. Count the total number of nodes in the list
	length := 0
	curr := head
	for curr != nil {
		length++
		curr = curr.Next
	}

	// Use a dummy node to safely manage the new head of the list
	dummy := &Node{Next: head}

	// 2. Iterate step sizes: 1, 2, 4, 8, ... up to the length of the list
	for step := 1; step < length; step *= 2 {
		prev := dummy
		curr = dummy.Next

		// Process the entire list for the current step size
		for curr != nil {
			// Extract the left sub-list of size 'step'
			left := curr
			right := split(left, step)

			// Extract the right sub-list of size 'step' and get the next starting node
			curr = split(right, step)

			// Merge the two halves and attach them to the processed chain
			prev.Next = merge(left, right)

			// Move 'prev' to the end of the newly merged sub-list
			for prev.Next != nil {
				prev = prev.Next
			}
		}
	}

	return dummy.Next
}

// split cuts the list after 'step' nodes and returns the head of the remaining list
func split(head *Node, step int) *Node {
	if head == nil {
		return nil
	}

	// Move forward 'step' times or until the end of the list
	curr := head
	for i := 1; i < step && curr.Next != nil; i++ {
		curr = curr.Next
	}

	// Disconnect the sub-list and return the remaining segment
	remainder := curr.Next
	curr.Next = nil
	return remainder
}

// merge combines two sorted lists and returns the head of the merged list
func merge(left, right *Node) *Node {
	dummy := &Node{}
	curr := dummy

	for left != nil && right != nil {
		if left.Val <= right.Val {
			curr.Next = left
			left = left.Next
		} else {
			curr.Next = right
			right = right.Next
		}
		curr = curr.Next
	}

	if left != nil {
		curr.Next = left
	} else {
		curr.Next = right
	}

	return dummy.Next
}

// printList is a helper function to display the list
func printList(head *Node) {
	for head != nil {
		fmt.Printf("%d -> ", head.Val)
		head = head.Next
	}
	fmt.Println("nil")
}

func main() {
	// Create an unsorted list: 5 -> 1 -> 4 -> 2 -> 3 -> nil
	head := &Node{Val: 5}
	head.Next = &Node{Val: 1}
	head.Next.Next = &Node{Val: 4}
	head.Next.Next.Next = &Node{Val: 2}
	head.Next.Next.Next.Next = &Node{Val: 3}

	fmt.Print("Original List: ")
	printList(head)

	sortedHead := IterativeMergeSort(head)

	fmt.Print("Sorted List:   ")
	printList(sortedHead)
}
