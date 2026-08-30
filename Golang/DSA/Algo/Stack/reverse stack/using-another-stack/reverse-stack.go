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

// ReverseStack reverses a stack using only one extra auxiliary stack and returns it.
func ReverseStack[T any](original *Stack[T]) *Stack[T] {
	aux1 := &Stack[T]{}

	// Move all elements from original to aux1 (this reverses the order once)
	for !original.IsEmpty() {
		val, _ := original.Pop()
		aux1.Push(val)
	}

	return aux1
}

func main() {
	stack := &Stack[int]{}
	stack.Push(1)
	stack.Push(2)
	stack.Push(3)
	stack.Push(4)

	fmt.Println("Original stack items (bottom to top):", stack.items)

	stack = ReverseStack(stack)

	fmt.Println("Reversed stack items (bottom to top):", stack.items)
}
