package main

import "fmt"

func reverseSlice(s []int) {
	// i starts at beginning, j starts at the end. Move toward the center.
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i] // Swap elements
	}
}

func main() {
	arr := []int{1, 2, 3, 4, 5}
	reverseSlice(arr)
	fmt.Println(arr)
	// Output: [5 4 3 2 1]
}
