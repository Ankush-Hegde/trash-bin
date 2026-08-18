package main

import "fmt"

// InsertionSort sorts a slice of integers in ascending order
func InsertionSort(arr []int) {
	n := len(arr)

	// Start from the second element (index 1)
	for i := 1; i < n; i++ {
		key := arr[i]
		j := i - 1

		// Move elements that are greater than key to one position ahead
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		// Place the key at its correct position
		arr[j+1] = key
	}
}

func main() {
	numbers := []int{12, 11, 13, 5, 6}
	fmt.Println("Original array:", numbers)

	InsertionSort(numbers)
	fmt.Println("Sorted array:  ", numbers)
}
