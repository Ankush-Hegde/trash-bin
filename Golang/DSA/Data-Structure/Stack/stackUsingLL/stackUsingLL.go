package main

import "fmt"

type Node struct {
	data int
	next *Node
}

func NewNode(data int) *Node {
	return &Node{
		data: data,
		next: nil,
	}
}

func (n *Node) pop() *Node {
	if n == nil {
		return nil
	}
	return n.next
}

func (n *Node) push(data int) *Node {
	newNode := NewNode(data)
	newNode.next = n

	return newNode
}

func (n *Node) peek() int {
	if n == nil {
		return 0
	}
	return n.data
}

func (n *Node) isEmpty() bool {
	return n == nil
}

func (n *Node) size() {

}

func main() {
	var stack *Node

	stack = stack.push(4)
	stack = stack.push(3)
	stack = stack.push(2)
	stack = stack.push(1)

	fmt.Println(stack.data) // 1
	stack = stack.pop()

}
