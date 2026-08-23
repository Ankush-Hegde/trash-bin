package main

import "fmt"

// ListNode defines a node in a singly linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

// insertionSortList sorts a singly linked list using insertion sort in place.
func insertionSortList(head *ListNode) *ListNode {
	// Return immediately if list has 0 or 1 nodes.
	if head == nil || head.Next == nil {
		return head
	}

	// Create a dummy node to simplify insertions at the true head.
	dummy := &ListNode{Next: head}

	// lastSorted tracks the boundary of the sorted portion.
	// curr is the first node of the unsorted portion.
	lastSorted := head
	curr := head.Next

	for curr != nil {
		if lastSorted.Val <= curr.Val {
			// If already sorted relative to the last element, just advance lastSorted.
			lastSorted = lastSorted.Next
		} else {
			// Otherwise, find the right spot starting from the dummy node.
			prev := dummy
			// prev.Next != nil ensures we don't panic.
			// prev.Next.Val < curr.Val finds the insertion point.
			for prev.Next != nil && prev.Next.Val < curr.Val {
				prev = prev.Next
			}

			// Remove curr from its old position and link lastSorted past it.
			lastSorted.Next = curr.Next

			// Insert curr between prev and prev.Next
			curr.Next = prev.Next
			prev.Next = curr

			// Note: curr is now safely placed, and lastSorted remains
			// pointing to the end of the sorted sublist because lastSorted.Next
			// was updated to skip over curr.
		}
		// Move to the next unsorted node.
		curr = lastSorted.Next
	}

	return dummy.Next
}

// Helper function to print a linked list.
func printList(head *ListNode) {
	for head != nil {
		fmt.Printf("%d -> ", head.Val)
		head = head.Next
	}
	fmt.Println("nil")
}

func main() {
	// Create unsorted list: 4 -> 2 -> 1 -> 3 -> nil
	head := &ListNode{Val: 4, Next: &ListNode{Val: 2, Next: &ListNode{Val: 1, Next: &ListNode{Val: 3}}}}

	fmt.Print("Original list: ")
	printList(head)

	sortedHead := insertionSortList(head)

	fmt.Print("Sorted list:   ")
	printList(sortedHead)
}
