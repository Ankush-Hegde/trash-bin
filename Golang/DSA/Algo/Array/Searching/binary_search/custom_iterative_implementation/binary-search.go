package main

import "fmt"

func binarySearch(arr []int, target int) int {
	low := 0
	high := len(arr) - 1

	for low <= high {
		// Avoid potential integer overflow compared to (low + high) / 2
		mid := low + (high-low)/2

		if arr[mid] == target {
			return mid // Element found
		}
		if arr[mid] < target {
			low = mid + 1 // Search right half
		} else {
			high = mid - 1 // Search left half
		}
	}
	return -1 // Element not found
}

func main() {
	numbers := []int{10, 20, 30, 40, 50}
	fmt.Println(binarySearch(numbers, 40)) // Output: 3
	fmt.Println(binarySearch(numbers, 99)) // Output: -1
}
