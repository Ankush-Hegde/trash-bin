package main

import "fmt"

// BubbleSort sorts a slice of integers in ascending order
func BubbleSort(arr []int) {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		swapped := false

		// Last i elements are already in place
		for j := 0; j < n-i-1; j++ {
			if arr[j] > arr[j+1] {
				// Swap adjacent elements
				arr[j], arr[j+1] = arr[j+1], arr[j]
				swapped = true
			}
		}

		// Optimization: If no elements were swapped, array is sorted
		if !swapped {
			break
		}
	}
}

func main() {
	numbers := []int{64, 34, 25, 12, 22, 11, 90}
	fmt.Println("Original array:", numbers)

	BubbleSort(numbers)
	fmt.Println("Sorted array:  ", numbers)
}
