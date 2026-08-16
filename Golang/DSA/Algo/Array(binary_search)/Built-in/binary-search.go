package main

import (
	"fmt"
	"slices"
)

func main() {
	// The array/slice MUST be sorted
	numbers := []int{10, 20, 30, 40, 50}

	// Search for an existing element
	index, found := slices.BinarySearch(numbers, 30)
	fmt.Printf("Found: %t, Index: %d\n", found, index) // Found: true, Index: 2

	// Search for a missing element
	index2, found2 := slices.BinarySearch(numbers, 45)
	fmt.Printf("Found: %t, Index: %d\n", found2, index2) // Found: false, Index: 4 (insertion point)
}
