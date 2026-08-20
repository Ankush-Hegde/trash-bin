package main

import "fmt"

func main() {
	// 1. Declaration with default zero-values (allocates memory for 3 integers, all initialized to 0)
	var numbers [3]int

	// 2. Initializing with a composite literal
	primes := [5]int{2, 3, 5, 7, 11}
	arr := [3]int{10, 20, 30}

	// 3. Inferring the length using ellipsis (...) based on the number of elements provided
	colors := [...]string{"Red", "Green", "Blue"}

	// 4. Initializing specific indices (index 1 is "B", index 3 is "D", others are "")
	sparse := [5]string{1: "B", 3: "D"}

	fmt.Println(numbers) // Output: [0 0 0]
	fmt.Println(primes)  // Output: [2 3 5 7 11]
	fmt.Println(colors)  // Output: [Red Green Blue]
	fmt.Println(sparse)  // Output: [ B  D ]

	// -----------------------------------------------------------
	// operations on arrays
	// Access and Update elements via 0-based indexing
	arr[1] = 25
	fmt.Println("First element:", arr[0]) // Output: 10

	// Check length using len()
	fmt.Println("Array length:", len(arr)) // Output: 3

	// Iterating using for-range
	for index, value := range arr {
		fmt.Printf("Index: %d, Value: %d\n", index, value)
	}
}
