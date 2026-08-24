package main

import "fmt"

// ListNode represents a node in the linked list
type ListNode struct {
	Value int
	Next  *ListNode
}

func findNthNodeFromEnd(head *ListNode, n int) *ListNode {
	if head == nil || n <= 0 {
		return nil
	}

	fast, slow := head, head
	for i := 0; i < n; i++ {
		if fast == nil {
			return nil // n is greater than the length of the list
		}
		fast = fast.Next
	}

	for fast != nil {
		slow = slow.Next
		fast = fast.Next
	}

	return slow
}

// Helper function to print the list and show where the loop connects back
func printList(head *ListNode) {
	curr := head
	visited := make(map[*ListNode]bool)

	for curr != nil {
		// If we encounter a node we've already visited, we found the loop target
		if visited[curr] {
			fmt.Printf("(Loop continues... points back to Node %d)\n", curr.Value)
			return
		}

		visited[curr] = true
		fmt.Printf("%d -> ", curr.Value)
		curr = curr.Next
	}

	fmt.Println("nil")
}

func main() {
	// Create nodes: 1 -> 2 -> 3 -> 4 -> 5
	n1 := &ListNode{Value: 1}
	n2 := &ListNode{Value: 2}
	n3 := &ListNode{Value: 3}
	n4 := &ListNode{Value: 4}
	n5 := &ListNode{Value: 5}

	n1.Next = n2
	n2.Next = n3
	n3.Next = n4
	n4.Next = n5

	fmt.Println("list:")
	printList(n1)

	fmt.Println("\n n: 2 and node from end:")
	result := findNthNodeFromEnd(n1, 2)
	if result != nil {
		fmt.Printf("The 2nd node from the end has value: %d\n", result.Value)
	} else {
		fmt.Println("Node not found")
	}
}
