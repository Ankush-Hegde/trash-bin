package main

import (
	"fmt"
)

// insertElement inserts a value into a slice at a specific target index
func insertElement(slice []int, value int, index int) ([]int, error) {
	// Validate if the index is within logical bounds
	if index < 0 || index > len(slice) {
		return nil, fmt.Errorf("index %d out of bounds for slice of length %d", index, len(slice))
	}

	// 1. Append a placeholder zero value to expand the slice capacity/length
	slice = append(slice, 0)

	// 2. Shift all elements from the target index to the right by one position
	for i := len(slice) - 1; i > index; i-- {
		slice[i] = slice[i-1]
	}

	// 3. Place the new value into the target index
	slice[index] = value

	return slice, nil
}

func main() {
	// Original slice
	numbers := []int{10, 20, 30, 40, 50}
	targetIndex := 2
	newValue := 99

	fmt.Println("Original slice:", numbers)

	// Perform insertion
	updatedNumbers, err := insertElement(numbers, newValue, targetIndex)
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	fmt.Printf("After inserting %d at index %d: %v\n", newValue, targetIndex, updatedNumbers)
}
