package main

import (
	"errors"
	"fmt"
)

type DynamicStack struct {
	items []int
}

func NewDynamicStack() *DynamicStack {
	return &DynamicStack{
		items: make([]int, 0),
	}
}

func (s *DynamicStack) Push(data int) {
	s.items = append(s.items, data)
}

func (s *DynamicStack) Pop() (int, error) {
	if s.IsEmpty() {
		return 0, errors.New("stack underflow: stack is empty")
	}
	topIndex := len(s.items) - 1
	data := s.items[topIndex]
	// this will not shrink the underlying array,
	// but it will reduce the length of the slice
	// you can use linked list for a more complex
	// dynamic array implementation if you want to shrink the underlying array
	s.items = s.items[:topIndex]
	return data, nil
}

func (s *DynamicStack) Peek() (int, error) {
	if s.IsEmpty() {
		return 0, errors.New("stack underflow: stack is empty")
	}
	return s.items[len(s.items)-1], nil
}

func (s *DynamicStack) IsEmpty() bool {
	return len(s.items) == 0
}

func (s *DynamicStack) Size() int {
	return len(s.items)
}

func main() {
	stack := NewDynamicStack()

	fmt.Printf("Is empty? %t\n", stack.IsEmpty())
	fmt.Printf("pushing 10, 20, 30, 40 (no capacity limit)\n")

	stack.Push(10)
	stack.Push(20)
	stack.Push(30)
	stack.Push(40) // Automatically resizes/grows under the hood

	val, _ := stack.Peek()
	fmt.Printf("Peek: %d\n", val)
	fmt.Printf("Size: %d\n", stack.Size())

	for !stack.IsEmpty() {
		popped, _ := stack.Pop()
		fmt.Printf("Popped: %d\n", popped)
	}

	// Testing Stack Underflow
	_, err := stack.Pop()
	if err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Printf("Is empty? %t\n", stack.IsEmpty())
}
