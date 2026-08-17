package main

import "fmt"

func quick(arr []int, low, high int) {
	if low < high {
		p := partition(arr, low, high)
		quick(arr, low, p-1)
		quick(arr, p+1, high)
	}
}

func partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low

	for j := low; j < high; j++ {
		if arr[j] < pivot {
			arr[i], arr[j] = arr[j], arr[i]
			i++
		}
	}

	arr[i], arr[high] = arr[high], arr[i]
	return i
}

func QuickSort(arr []int) {
	if len(arr) > 1 {
		quick(arr, 0, len(arr)-1)
	}
}

func main() {
	numbers := []int{10, 7, 8, 9, 1, 5}
	QuickSort(numbers)
	fmt.Println("Sorted:", numbers) // Output: [1 5 7 8 9 10]
}
