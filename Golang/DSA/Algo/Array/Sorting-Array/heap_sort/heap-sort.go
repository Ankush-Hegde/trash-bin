package main

import "fmt"

// HeapSort sorts a slice of integers in ascending order
func HeapSort(arr []int) {
	n := len(arr)

	// Build max heap (rearrange array)
	for i := n/2 - 1; i >= 0; i-- {
		heapify(arr, n, i)
	}

	// One by one extract elements from the heap
	for i := n - 1; i > 0; i-- {
		// Move current root to end
		arr[0], arr[i] = arr[i], arr[0]

		// Call max heapify on the reduced heap
		heapify(arr, i, 0)
	}
}

// heapify maintains the max-heap property for a subtree rooted at index i
func heapify(arr []int, n int, i int) {
	largest := i
	left := 2*i + 1
	right := 2*i + 2

	// If left child is larger than root
	if left < n && arr[left] > arr[largest] {
		largest = left
	}

	// If right child is larger than largest so far
	if right < n && arr[right] > arr[largest] {
		largest = right
	}

	// If largest is not root
	if largest != i {
		arr[i], arr[largest] = arr[largest], arr[i]

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest)
	}
}

func main() {
	numbers := []int{12, 11, 13, 5, 6, 7}
	fmt.Println("Original array:", numbers)

	HeapSort(numbers)
	fmt.Println("Sorted array:  ", numbers)
}
