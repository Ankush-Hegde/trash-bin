package main

import (
	"errors"
	"fmt"
)

type ArrayStack struct {
	items    []int
	top      int
	capacity int
}

func NewArrayStack(capacity int) *ArrayStack {
	return &ArrayStack{
		items:    make([]int, capacity), // initialize the slice with the specified capacity
		top:      -1,                    // index of the top element
		capacity: capacity,              // size of stack
	}
}

func (s *ArrayStack) Push(data int) error {
	if s.top >= s.capacity-1 {
		return errors.New("stack overflow: capacity exceeded")
	}
	s.top++
	s.items[s.top] = data
	return nil
}

func (s *ArrayStack) Pop() (int, error) {
	if s.top < 0 {
		return 0, errors.New("stack underflow: stack is empty")
	}
	data := s.items[s.top]
	s.top--
	return data, nil
}

func (s *ArrayStack) Peek() (int, error) {
	if s.top < 0 {
		return 0, errors.New("stack underflow: stack is empty")
	}
	return s.items[s.top], nil
}

func (s *ArrayStack) IsEmpty() bool {
	return s.top == -1
}

func (s *ArrayStack) IsFull() bool {
	return s.top == s.capacity-1
}

func (s *ArrayStack) Size() int {
	return s.top + 1
}

func main() {
	stack := NewArrayStack(3)

	fmt.Printf("Is empty? %t\n", stack.IsEmpty())

	fmt.Printf("pushing 10, 20, 30 to stack\n")
	if err := stack.Push(10); err != nil {
		fmt.Println(err)
	}
	if err := stack.Push(20); err != nil {
		fmt.Println(err)
	}
	if err := stack.Push(30); err != nil {
		fmt.Println(err)
	}

	// Testing Stack Overflow
	fmt.Printf("pushing 40 to stack\n")
	err := stack.Push(40)
	if err != nil {
		fmt.Println(err)
	}

	val, _ := stack.Peek()
	fmt.Printf("Peek: %d\n", val)
	fmt.Printf("Size: %d\n", stack.Size())
	fmt.Printf("Is full? %t\n", stack.IsFull())

	popped, _ := stack.Pop()
	fmt.Printf("Popped: %d\n", popped)

	popped, _ = stack.Pop()
	fmt.Printf("Popped: %d\n", popped)

	popped, _ = stack.Pop()
	fmt.Printf("Popped: %d\n", popped)

	// Testing Stack Underflow
	_, err = stack.Pop()
	if err != nil {
		fmt.Println(err)
	}

	fmt.Printf("Is empty? %t\n", stack.IsEmpty())
}
