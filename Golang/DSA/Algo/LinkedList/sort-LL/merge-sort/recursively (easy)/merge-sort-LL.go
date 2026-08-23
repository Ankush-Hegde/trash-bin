package main

import "fmt"

// Node represents a single element in the linked list
type Node struct {
	Val  int
	Next *Node
}

// MergeSort is the main function that sorts the linked list and returns the new head
func MergeSort(head *Node) *Node {
	// Base case: if list is empty or has only one element, it is already sorted
	if head == nil || head.Next == nil {
		return head
	}

	// 1. Split the list into two halves
	mid := getMiddle(head)
	nextToMid := mid.Next
	mid.Next = nil // Break the link to separate the two halves

	// 2. Recursively sort both halves
	left := MergeSort(head)
	right := MergeSort(nextToMid)

	// 3. Merge the sorted halves back together
	return merge(left, right)
}

// getMiddle finds the midpoint of the linked list using the slow/fast pointer technique
func getMiddle(head *Node) *Node {
	if head == nil {
		return head
	}

	slow := head
	fast := head

	// Move fast by two steps and slow by one step
	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	return slow
}

// merge combines two sorted linked lists into a single sorted linked list
func merge(left, right *Node) *Node {
	// Use a dummy node to simplify the head tracking
	dummy := &Node{}
	curr := dummy

	// Compare nodes from both halves and link the smaller one
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

	// If elements remain in left or right list, append them directly
	if left != nil {
		curr.Next = left
	}
	if right != nil {
		curr.Next = right
	}

	return dummy.Next
}

// printList is a helper function to print the linked list
func printList(head *Node) {
	for head != nil {
		fmt.Printf("%d -> ", head.Val)
		head = head.Next
	}
	fmt.Println("nil")
}

func main() {
	// Create an unsorted list: 4 -> 2 -> 1 -> 3 -> nil
	head := &Node{Val: 4}
	head.Next = &Node{Val: 2}
	head.Next.Next = &Node{Val: 1}
	head.Next.Next.Next = &Node{Val: 3}

	fmt.Print("Original List: ")
	printList(head)

	sortedHead := MergeSort(head)

	fmt.Print("Sorted List:   ")
	printList(sortedHead)
}
