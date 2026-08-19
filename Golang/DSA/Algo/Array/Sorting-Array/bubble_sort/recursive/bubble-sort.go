package main

import "fmt"

func recursiveBubbleSort(arr []int, n int) {
	// Base case: If array size is 1, it's already sorted
	if n == 1 {
		return
	}

	swapped := false

	// One pass of bubble sort. After this pass, the largest element
	// is bubbled to the end of the current sub-array.
	for i := 0; i < n-1; i++ {
		if arr[i] > arr[i+1] {
			arr[i], arr[i+1] = arr[i+1], arr[i]
			swapped = true
		}
	}

	// Optimization: If no elements were swapped, the array is already sorted
	if !swapped {
		return
	}

	// Recursive call for the remaining n-1 elements
	recursiveBubbleSort(arr, n-1)
}

func main() {
	nums := []int{64, 34, 25, 12, 22, 11, 90}
	fmt.Println("Original array:", nums)

	recursiveBubbleSort(nums, len(nums))
	fmt.Println("Sorted array:  ", nums)
}
