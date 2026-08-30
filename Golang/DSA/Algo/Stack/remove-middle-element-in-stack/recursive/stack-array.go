package main

import "fmt"

// Stack represents a generic stack using a Go slice.
type Stack struct {
	elements []int
}

// Push adds an element to the top of the stack.
func (s *Stack) Push(val int) {
	s.elements = append(s.elements, val)
}

// Pop removes and returns the top element of the stack.
func (s *Stack) Pop() int {
	if s.IsEmpty() {
		return 0
	}
	topIndex := len(s.elements) - 1
	val := s.elements[topIndex]
	s.elements = s.elements[:topIndex]
	return val
}

// IsEmpty checks if the stack has no elements.
func (s *Stack) IsEmpty() bool {
	return len(s.elements) == 0
}

// Size returns the current number of elements in the stack.
func (s *Stack) Size() int {
	return len(s.elements)
}

// deleteMidUtil is the recursive helper function.
func deleteMidUtil(s *Stack, sizeOfStack int, current int) {
	// Base case: If current pointer reaches the middle index, pop the middle element.
	if current == sizeOfStack/2 {
		// if current starts with 0 then mid = sizeOfStack/2
		// if current starts with 1 then mid = [(sizeOfStack/2 ) + 1]
		s.Pop()
		return
	}

	// Hold the top element in the function call stack and pop it.
	topElement := s.Pop()

	// Recursive call for the next element.
	deleteMidUtil(s, sizeOfStack, current+1)

	// Push the stored element back after the recursion unwinds.
	s.Push(topElement)
}

// DeleteMid initiates the recursive middle-deletion process.
func DeleteMid(s *Stack) {
	size := s.Size()
	if size == 0 {
		return
	}
	deleteMidUtil(s, size, 0)
}

func main() {
	st := &Stack{}
	// Push elements: bottom -> [10, 20, 30, 40, 50] -> top
	for _, val := range []int{10, 20, 30, 40, 50} {
		st.Push(val)
	}

	fmt.Printf("Original Stack (Top to Bottom): %v\n", st.elements)

	DeleteMid(st)

	fmt.Printf("Stack after deleting middle (Top to Bottom): %v\n", st.elements)
}
