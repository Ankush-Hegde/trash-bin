// linear search is used in unsorted array
// for sorted array use binary search
package main

import "fmt"

// linearSearch scans the slice sequentially for the target.
// Returns the index if found, or -1 if not found.
func linearSearch(arr []int, target int) int {
	for index, value := range arr {
		if value == target {
			return index // Target found, return its index immediately
		}
	}
	return -1 // Traversed entire slice, target not found
}

func main() {
	numbers := []int{10, 50, 30, 70, 80, 20}
	target := 30

	result := linearSearch(numbers, target)

	if result != -1 {
		fmt.Printf("Element %d found at index %d\n", target, result)
	} else {
		fmt.Printf("Element %d not found\n", target)
	}
}
