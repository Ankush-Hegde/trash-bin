package main

import "fmt"

// Stack represents a generic stack data structure using a slice.
type Stack[T any] struct {
	items []T
}

func (s *Stack[T]) Push(item T) {
	s.items = append(s.items, item)
}

func (s *Stack[T]) Pop() (T, bool) {
	if len(s.items) == 0 {
		var zero T
		return zero, false
	}
	index := len(s.items) - 1
	item := s.items[index]
	s.items = s.items[:index]
	return item, true
}

func (s *Stack[T]) IsEmpty() bool {
	return len(s.items) == 0
}

// insertAtBottom recursively inserts an element at the bottom of the stack.
func insertAtBottom[T any](s *Stack[T], item T) {
	if s.IsEmpty() {
		s.Push(item)
		return
	}

	top, _ := s.Pop()
	insertAtBottom(s, item)
	s.Push(top)
}

// ReverseStack reverses a stack in-place using only the call stack (one structural stack).
func ReverseStack[T any](s *Stack[T]) {
	if s.IsEmpty() {
		return
	}

	top, _ := s.Pop()
	ReverseStack(s)
	insertAtBottom(s, top)
}

func main() {
	stack := &Stack[int]{}
	stack.Push(1)
	stack.Push(2)
	stack.Push(3)
	stack.Push(4)

	fmt.Println("Original stack items (bottom to top):", stack.items)

	ReverseStack(stack)

	fmt.Println("Reversed stack items (bottom to top):", stack.items)
}
