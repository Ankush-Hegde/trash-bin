package main

import "fmt"

// Node represents a node in the linked list
type Node struct {
	Value int
	Next  *Node
}

// FindMeetingPoint checks if a linked list contains a loop using Floyd's Cycle-Finding Algorithm.
// It returns the meeting node if a cycle exists, or nil otherwise.
func FindMeetingPoint(head *Node) *Node {
	fastPointer := head
	slowPointer := head

	for fastPointer != nil && fastPointer.Next != nil {
		fastPointer = fastPointer.Next.Next
		slowPointer = slowPointer.Next
		if fastPointer == slowPointer {
			return slowPointer // Return the meeting point
		}
	}
	return nil
}

// FindLoopEntryPoint finds the exact node where the loop begins
func FindLoopEntryPoint(head *Node) *Node {
	meetingPoint := FindMeetingPoint(head)
	if meetingPoint == nil {
		return nil // No cycle, so no entry point
	}

	slow := head
	fast := meetingPoint

	// Case A: The loop starts right at the head node
	if slow == meetingPoint {
		return head
	}

	// Case B: Move both one step at a time until they meet at the entry point
	for slow != fast {
		slow = slow.Next
		fast = fast.Next
	}

	return slow // This is the exact entry point
}

// RemoveLoop detects and removes a loop in the linked list
func RemoveLoop(head *Node) {
	// Step 1: Get the meeting point inside the loop (returns nil if no loop)
	meetingPoint := FindMeetingPoint(head)
	if meetingPoint == nil {
		return
	}

	// Step 2: Find the entry point and the last node of the loop

	// After the fast and slow pointers meet inside the loop, the next step is to find the exact entry point.
	// You do this by resetting the slow pointer back to the beginning of the list, while the fast pointer stays at the meeting point.
	// Then, you move both pointers forward one step at a time. Where they meet again is the exact start of the loop.
	slow := head
	fast := meetingPoint

	// Case A: The loop starts right at the head node
	if slow == meetingPoint {
		for fast.Next != slow {
			fast = fast.Next
		}
		fast.Next = nil
		return
	}

	// Case B: The loop starts somewhere inside the list
	for slow.Next != fast.Next {
		slow = slow.Next
		fast = fast.Next
	}

	// fast now points to the last node of the loop
	fast.Next = nil
}

// Helper function to print the list and show where the loop connects back
func printList(head *Node) {
	curr := head
	visited := make(map[*Node]bool)

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
	n1 := &Node{Value: 1}
	n2 := &Node{Value: 2}
	n3 := &Node{Value: 3}
	n4 := &Node{Value: 4}
	n5 := &Node{Value: 5}

	n1.Next = n2
	n2.Next = n3
	n3.Next = n4
	n4.Next = n5

	// Create a loop: 5 -> 3
	n5.Next = n3

	fmt.Println("Before removing loop:")
	printList(n1)

	meet := FindMeetingPoint(n1)
	if meet != nil {
		fmt.Printf("Has cycle: true\n")
		fmt.Printf("-> Meeting point value: %d\n", meet.Value)

		entryPoint := FindLoopEntryPoint(n1)
		if entryPoint != nil {
			fmt.Printf("-> Loop entry point value: %d\n", entryPoint.Value)
		}
	} else {
		fmt.Println("Has cycle: false")
	}

	// Remove the loop
	RemoveLoop(n1)

	fmt.Println("\nAfter removing loop:")
	printList(n1)
}
