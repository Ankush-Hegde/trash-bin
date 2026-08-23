package main

import "fmt"

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	fastPointer := head
	slowPointer := head
	for fastPointer != nil && fastPointer.Next != nil {
		fastPointer = fastPointer.Next.Next
		slowPointer = slowPointer.Next
		if fastPointer == slowPointer {
			return true
		}
	}
	return false
}

func main() {
	// Test Case 1: Linked list with a cycle (Tail connects back to index 1)
	node1 := &ListNode{Val: 3}
	node2 := &ListNode{Val: 2}
	node3 := &ListNode{Val: 0}
	node4 := &ListNode{Val: -4}

	node1.Next = node2
	node2.Next = node3
	node3.Next = node4
	node4.Next = node2 // Creates the cycle here

	fmt.Println("Test 1 (Has cycle):", hasCycle(node1)) // Expected: true

	// Test Case 2: Linked list without a cycle
	head2 := &ListNode{Val: 1}
	head2.Next = &ListNode{Val: 2}

	fmt.Println("Test 2 (No cycle):", hasCycle(head2)) // Expected: false
}
