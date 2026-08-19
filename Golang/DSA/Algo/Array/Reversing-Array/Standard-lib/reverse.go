package main

import (
	"fmt"
	"slices" // Requires Go 1.21 or later
)

func main() {
	// Works identically on a slice or a sliced array
	numbers := []int{10, 20, 30, 40, 50}

	slices.Reverse(numbers)

	fmt.Println(numbers)
	// Output: [50 40 30 20 10]
}
