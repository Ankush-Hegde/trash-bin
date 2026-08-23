package main

import "fmt"

// Node represents a single element in the linked list
type Node struct {
	Val  int
	Next *Node
}

// using slow and fast pointer approach
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

func (n *Node) traverse() {
	CurrentNode := n
	for CurrentNode != nil {
		fmt.Printf("%d -> ", CurrentNode.Val)
		CurrentNode = CurrentNode.Next
	}
	fmt.Println("nil")
}

func main() {
	head := &Node{Val: 4}
	head.Next = &Node{Val: 2}
	head.Next.Next = &Node{Val: 1}
	head.Next.Next.Next = &Node{Val: 3}

	head.traverse()

	mid := getMiddle(head)
	fmt.Printf("middle node :%d", mid.Val)

}
