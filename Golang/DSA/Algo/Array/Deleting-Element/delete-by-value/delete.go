package main

import "fmt"

func deleteByValue(s []int, value int) []int {
	for i := 0; i < len(s); i++ {
		if s[i] == value {
			// Found the value; remove it by shifting elements
			return append(s[:i], s[i+1:]...)
		}
	}
	return s // Return original slice if value is not found
}

func main() {
	arr := []int{10, 20, 30, 40, 50}
	targetValue := 30

	arr = deleteByValue(arr, targetValue)
	fmt.Println(arr)
	// Output: [10 20 40 50]
}
