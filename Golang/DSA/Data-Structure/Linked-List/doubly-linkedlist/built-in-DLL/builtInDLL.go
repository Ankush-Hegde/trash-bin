package main

import (
	"container/list"
	"fmt"
)

func main() {
	// 1. Initialization: list.New()
	l := list.New()

	// 2. PushFront and PushBack
	elementStart := l.PushFront("Start")
	elementMiddle := l.PushBack("Middle")
	elementEnd := l.PushBack("End")

	// 3. InsertBefore and InsertAfter
	// Inserts "BeforeMiddle" before elementMiddle
	markBefore := l.InsertBefore("BeforeMiddle", elementMiddle)
	// Inserts "AfterMiddle" after elementMiddle
	l.InsertAfter("AfterMiddle", elementMiddle)

	// 4. Len: Returns the number of elements
	fmt.Printf("Initial Length: %d\n", l.Len())

	// 5. Front and Back: Access first and last elements
	fmt.Printf("Front Element: %v\n", l.Front().Value)
	fmt.Printf("Back Element: %v\n", l.Back().Value)

	// 6. Move operations (MoveToFront, MoveToBack, MoveBefore, MoveAfter)
	l.MoveToFront(elementEnd)               // Moves "End" to the very front
	l.MoveToBack(elementStart)              // Moves "Start" to the very back
	l.MoveBefore(elementMiddle, markBefore) // Re-orders elements relative to marks
	l.MoveAfter(elementMiddle, elementEnd)

	// 7. List concatenation (PushBackList, PushFrontList)
	otherList := list.New()
	otherList.PushBack("Extra1")
	otherList.PushBack("Extra2")

	l.PushBackList(otherList)  // Appends another list to the back
	l.PushFrontList(otherList) // Appends another list to the front

	// 8. Traversal using Next() and Prev()
	fmt.Println("\nForward Traversal:")
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Printf("%v -> ", e.Value)
	}

	fmt.Println("\n\nBackward Traversal:")
	for e := l.Back(); e != nil; e = e.Prev() {
		fmt.Printf("%v -> ", e.Value)
	}

	// 9. Remove: Deletes a specific element from the list
	if elementMiddle != nil {
		l.Remove(elementMiddle)
	}

	fmt.Printf("\n\nFinal Length after removal: %d\n", l.Len())
}
