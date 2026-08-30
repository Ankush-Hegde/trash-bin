package main

import "fmt"

type Stack struct {
	elements []int
}

func (s *Stack) Push(val int) {
	s.elements = append(s.elements, val)
}

func (s *Stack) Pop() int {
	if s.IsEmpty() {
		return 0
	}
	topIndex := len(s.elements) - 1
	val := s.elements[topIndex]
	s.elements = s.elements[:topIndex]
	return val
}

func (s *Stack) IsEmpty() bool {
	return len(s.elements) == 0
}

func (s *Stack) Size() int {
	return len(s.elements)
}

// DeleteMidUsingAuxStack deletes the middle element using an auxiliary stack.
func DeleteMidUsingAuxStack(s *Stack) {
	size := s.Size()
	if size == 0 {
		return
	}

	auxStack := &Stack{}
	midIndex := size / 2

	// Move elements to the auxiliary stack until we reach the middle element from the top.
	// For a stack of size 5, we pop 2 elements to reach index 2 (the middle).
	for i := 0; i < midIndex; i++ {
		auxStack.Push(s.Pop())
	}

	// Discard the middle element.
	s.Pop()

	// Restore the elements back from the auxiliary stack to the original stack.
	for !auxStack.IsEmpty() {
		s.Push(auxStack.Pop())
	}
}

func main() {
	st := &Stack{}
	for _, val := range []int{10, 20, 30, 40, 50} {
		st.Push(val)
	}

	fmt.Printf("Original Stack (Top to Bottom): %v\n", st.elements)
	DeleteMidUsingAuxStack(st)
	fmt.Printf("Stack after deleting middle (Top to Bottom): %v\n", st.elements)
}
