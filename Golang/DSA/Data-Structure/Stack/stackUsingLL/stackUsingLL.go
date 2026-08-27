package main

import "fmt"

type Stack struct {
	head *Node
}

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

func (s *Stack) pop() *int {
	if s.head == nil {
		return nil
	}
	data := s.head.data
	s.head = s.head.next
	return &data
}

func (s *Stack) push(data int) {
	newNode := NewNode(data)
	newNode.next = s.head
	s.head = newNode
}

func (s *Stack) peek() (val *int) {
	if s.head == nil {
		return nil
	}
	val = &s.head.data
	return
}

func (s *Stack) isEmpty() bool {
	return s.head == nil
}

func (s *Stack) size() (count int) {
	current := s.head
	for current != nil {
		count++
		current = current.next
	}
	return
}

func (s *Stack) printStack() {
	if s.isEmpty() {
		fmt.Println("Stack is empty")
		return
	}

	current := s.head
	fmt.Print("Stack (top to bottom): \n")
	for current != nil {
		fmt.Printf(" | %d | \n", current.data)
		current = current.next
	}
	fmt.Println()
}

func main() {
	var stack Stack

	stack.push(4)
	stack.push(3)
	stack.push(2)
	stack.push(1)

	stack.printStack()

	fmt.Printf("size: %d\n", stack.size())
	fmt.Printf("peek: %d\n", *stack.peek())
	fmt.Printf("pop: %d\n", *stack.pop())
	fmt.Printf("size after pop: %d\n", stack.size())
	fmt.Printf("is empty: %t\n", stack.isEmpty())

	stack.printStack()
}
