package main

import "fmt"

type Node struct {
	data rune
	next *Node
}

type Stack struct {
	head *Node
}

func NewNode(data rune) *Node {
	return &Node{
		data: data,
		next: nil,
	}
}

func (s *Stack) pop() {
	s.head = s.head.next
}

func (s *Stack) push(data rune) {
	newNode := NewNode(data)
	newNode.next = s.head
	s.head = newNode
}

func (s *Stack) peek() rune {
	return s.head.data
}

func isValid(s string) bool {
	var stack Stack
	bracket := map[rune]rune{
		')': '(',
		']': '[',
		'}': '{',
	}

	for _, v := range s {
		if v == '(' || v == '[' || v == '{' {
			stack.push(v)
		} else {
			if stack.head == nil || (stack.peek() != bracket[v]) {
				return false
			}
			stack.pop()
		}
	}
	if stack.head == nil {
		return true
	}
	return false
}

func main() {
	testCases := []string{
		"()",
		"()[]{}",
		"(]",
		"([])",
		"([)]",
		"]",
	}

	for _, tc := range testCases {
		fmt.Printf("Input: %-6q -> Output: %v\n", tc, isValid(tc))
	}
}
