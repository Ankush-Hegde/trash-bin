package main

import "fmt"

func deleteElement(s []int, index int) []int {
	// Ensure the index is within valid bounds
	if index < 0 || index >= len(s) {
		return s
	}
	// Append everything before the index with everything after the index
	return append(s[:index], s[index+1:]...)
}

func main() {
	arr := []int{10, 20, 30, 40, 50}
	targetIndex := 2 // Deleting the element '30'

	arr = deleteElement(arr, targetIndex)
	fmt.Println(arr)
	// Output: [10 20 40 50]
}
