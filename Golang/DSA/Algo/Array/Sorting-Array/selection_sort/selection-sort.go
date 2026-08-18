package main

import "fmt"

// SelectionSort sorts a slice of integers in ascending order
func SelectionSort(arr []int) {
	n := len(arr)

	// One by one move the boundary of the unsorted subarray
	for i := 0; i < n-1; i++ {
		// Find the minimum element in the unsorted subarray
		minIdx := i
		for j := i + 1; j < n; j++ {
			if arr[j] < arr[minIdx] {
				minIdx = j
			}
		}

		// Swap the found minimum element with the first unsorted element
		if minIdx != i {
			arr[i], arr[minIdx] = arr[minIdx], arr[i]
		}
	}
}

func main() {
	numbers := []int{64, 25, 12, 22, 11}
	fmt.Println("Original array:", numbers)

	SelectionSort(numbers)
	fmt.Println("Sorted array:  ", numbers)
}
