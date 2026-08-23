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
	if list1 == nil {
		return list2
	}

	if list2 == nil {
		return list1
	}

	newList := &ListNode{}
	currentList1Node := list1
	currentList2Node := list2
	newListNode := newList

	for currentList1Node != nil && currentList2Node != nil {
		if currentList1Node.Val == currentList2Node.Val {
			newNode := ListNode{Val: currentList2Node.Val, Next: nil}
			newListNode.Next = &ListNode{Val: currentList1Node.Val, Next: &newNode}

			newListNode = newListNode.Next.Next
			currentList1Node = currentList1Node.Next
			currentList2Node = currentList2Node.Next
		} else if currentList1Node.Val > currentList2Node.Val {
			newListNode.Next = &ListNode{Val: currentList2Node.Val, Next: nil}

			newListNode = newListNode.Next
			currentList2Node = currentList2Node.Next
		} else if currentList1Node.Val < currentList2Node.Val {
			newListNode.Next = &ListNode{Val: currentList1Node.Val, Next: nil}

			newListNode = newListNode.Next
			currentList1Node = currentList1Node.Next
		}
	}

	if currentList1Node != nil {
		newListNode.Next = currentList1Node
	} else if currentList2Node != nil {
		newListNode.Next = currentList2Node
	}

	return newList.Next
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
	// Example 1: list1 = [1, 2, 4], list2 = [1, 3, 4]
	list1 := sliceToList([]int{1, 2, 4})
	list2 := sliceToList([]int{1, 3, 4})

	mergedHead := mergeTwoLists(list1, list2)

	fmt.Print("Merged List: ")
	printList(mergedHead) // Output should be: 1 1 2 3 4 4
}
