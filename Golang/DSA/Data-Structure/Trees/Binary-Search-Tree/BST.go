package main

import "fmt"

// Node represents an individual element in the tree
type Node struct {
	Val   int
	Left  *Node
	Right *Node
}

// Insert adds a new value into the binary search tree maintaining order
func (n *Node) Insert(val int) {
	if val < n.Val {
		if n.Left == nil {
			n.Left = &Node{Val: val}
		} else {
			n.Left.Insert(val)
		}
	} else {
		if n.Right == nil {
			n.Right = &Node{Val: val}
		} else {
			n.Right.Insert(val)
		}
	}
}

// InOrderTraversal visits Left -> Root -> Right (outputs sorted order for a BST)
func InOrderTraversal(n *Node) {
	if n == nil {
		return
	}
	InOrderTraversal(n.Left)
	fmt.Printf("%d ", n.Val)
	InOrderTraversal(n.Right)
}

// PreOrderTraversal visits Root -> Left -> Right
func PreOrderTraversal(n *Node) {
	if n == nil {
		return
	}
	fmt.Printf("%d ", n.Val)
	PreOrderTraversal(n.Left)
	PreOrderTraversal(n.Right)
}

// PostOrderTraversal visits Left -> Right -> Root
func PostOrderTraversal(n *Node) {
	if n == nil {
		return
	}
	PostOrderTraversal(n.Left)
	PostOrderTraversal(n.Right)
	fmt.Printf("%d ", n.Val)
}

func main() {
	// Initialize the root node
	root := &Node{Val: 10}

	// Insert additional nodes
	root.Insert(5)
	root.Insert(15)
	root.Insert(2)
	root.Insert(7)
	root.Insert(12)
	root.Insert(20)

	fmt.Print("In-Order (Sorted):   ")
	InOrderTraversal(root)
	fmt.Println()

	fmt.Print("Pre-Order:           ")
	PreOrderTraversal(root)
	fmt.Println()

	fmt.Print("Post-Order:          ")
	PostOrderTraversal(root)
	fmt.Println()
}
