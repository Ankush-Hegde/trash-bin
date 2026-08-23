package main

import "fmt"

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	// Base cases: if either list is empty, return the other
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}

	// Compare values and recurse
	if list1.Val <= list2.Val {
		list1.Next = mergeTwoLists(list1.Next, list2)
		return list1
	} else {
		list2.Next = mergeTwoLists(list1, list2.Next)
		return list2
	}
}

// Helper function to create a linked list from a slice of integers
func sliceToList(nums []int) *ListNode {
	if len(nums) == 0 {
		return nil
	}
	head := &ListNode{Val: nums[0]}
	curr := head
	for i := 1; i < len(nums); i++ {
		curr.Next = &ListNode{Val: nums[i]}
		curr = curr.Next
	}
	return head
}

// Helper function to print the linked list values
func printList(head *ListNode) {
	curr := head
	for curr != nil {
		fmt.Printf("%d ", curr.Val)
		curr = curr.Next
	}
	fmt.Println()
}

func main() {
	// Example: list1 = [1, 2, 4], list2 = [1, 3, 4]
	list1 := sliceToList([]int{1, 2, 4})
	list2 := sliceToList([]int{1, 3, 4})

	mergedHead := mergeTwoLists(list1, list2)

	fmt.Print("Merged List: ")
	printList(mergedHead) // Output: 1 1 2 3 4 4
}
