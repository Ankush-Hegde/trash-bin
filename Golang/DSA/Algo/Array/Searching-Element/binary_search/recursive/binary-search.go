package main

import "fmt"

// recursiveHelper handles the bounds of the search space
func recursiveHelper(arr []int, target, low, high int) int {
	if low > high {
		return -1 // Base case: element not found
	}

	mid := low + (high-low)/2

	if arr[mid] == target {
		return mid // Base case: element found
	} else if arr[mid] < target {
		return recursiveHelper(arr, target, mid+1, high) // Search right
	} else {
		return recursiveHelper(arr, target, low, mid-1) // Search left
	}
}

func binarySearchRecursive(arr []int, target int) int {
	return recursiveHelper(arr, target, 0, len(arr)-1)
}

func main() {
	numbers := []int{10, 20, 30, 40, 50}
	fmt.Println(binarySearchRecursive(numbers, 40)) // Output: 3
	fmt.Println(binarySearchRecursive(numbers, 99)) // Output: -1
}
