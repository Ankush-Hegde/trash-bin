package main

import "fmt"

func reverseSlice(s []int) {
	start := 0
	end := len(s) - 1

	// Go's "while" loop equivalent
	for start < end {
		s[start], s[end] = s[end], s[start] // Swap elements
		start++                             // Move start forward
		end--                               // Move end backward
	}
}

func main() {
	arr := []int{1, 2, 3, 4, 5}
	reverseSlice(arr)
	fmt.Println(arr)
	// Output: [5 4 3 2 1]
}
