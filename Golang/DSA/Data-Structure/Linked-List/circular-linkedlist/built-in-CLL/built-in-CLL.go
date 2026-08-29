package main

import (
	"container/ring"
	"fmt"
)

func main() {
	// 1. ring.New(n) - Creates a ring of size n
	r := ring.New(3)
	fmt.Printf("Initial ring length: %d\n", r.Len())

	// 2. r.Value - Assigns data to elements
	// 3. r.Next() - Moves pointer to the next element
	n := r.Len()
	for i := 1; i <= n; i++ {
		r.Value = i * 10
		r = r.Next()
	}

	fmt.Println("\n--- After Initialization ---")
	printRing(r)

	// 4. r.Prev() - Moves pointer to the previous element
	r = r.Prev()
	fmt.Printf("After moving to previous element, Value: %v\n", r.Value)

	// 5. r.Move(n) - Moves n elements forward (positive) or backward (negative)
	r = r.Move(2)
	fmt.Printf("After moving forward 2 positions, Value: %v\n", r.Value)

	r = r.Move(-1)
	fmt.Printf("After moving backward 1 position, Value: %v\n", r.Value)

	// 6. r.Link(s) - Connects ring r with ring s, inserting s elements after r
	// Let's create a new ring to link
	s := ring.New(2)
	s.Value = 99
	s.Next().Value = 88

	// Link s into r
	removed := r.Link(s)
	fmt.Println("\n--- After Linking a New Ring (values 99, 88) ---")
	printRing(r)
	fmt.Printf("Elements removed/overwritten by Link: ")
	removed.Do(func(p interface{}) {
		if p != nil {
			fmt.Printf("%v ", p)
		}
	})
	fmt.Println()

	// 7. r.Unlink(n) - Removes n elements from the ring starting after r.Next()
	// Unlink 2 elements from the current pointer position
	unlinked := r.Unlink(2)
	fmt.Println("\n--- After Unlinking 2 Elements ---")
	printRing(r)
	fmt.Printf("Unlinked elements: ")
	unlinked.Do(func(p interface{}) {
		if p != nil {
			fmt.Printf("%v ", p)
		}
	})
	fmt.Println()
	fmt.Printf("New ring length after unlink: %d\n", r.Len())

	// 8. r.Do(f) - Calls function f on each element of the ring in forward order
	fmt.Println("\n--- Iterating Using .Do() Method ---")
	r.Do(func(p interface{}) {
		fmt.Printf("-> %v ", p)
	})
	fmt.Println()
}

// Helper function to print elements starting from the current pointer
func printRing(r *ring.Ring) {
	fmt.Print("Ring elements: ")
	r.Do(func(p interface{}) {
		fmt.Printf("[%v] ", p)
	})
	fmt.Println()
}
