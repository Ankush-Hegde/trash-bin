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

	// -----------------------------------------------------------
	// multidimensional arrays (arrays of arrays)
	// Declares a 2x3 integer matrix (2 rows, 3 columns)
	matrix := [2][3]int{
		{1, 2, 3},
		{4, 5, 6},
	}
	fmt.Println(matrix[1][2]) // Accesses row 1, column 2. Output: 6

	// -----------------------------------------------------------
	// SLICES IN GOLANG (Dynamic arrays)
	// -----------------------------------------------------------

	// 1. Creating a slice by slicing an existing array
	// Syntax: array[start_index:end_index] (includes start_index, excludes end_index)
	sliceFromPrimes := primes[1:4] // Grabs indices 1, 2, and 3 -> [3, 5, 7]
	fmt.Println("Slice from primes array:", sliceFromPrimes)

	// 2. Modifying a slice alters the underlying array!
	sliceFromPrimes[0] = 99
	fmt.Println("Modified slice:", sliceFromPrimes) // Output: [99, 5, 7]
	fmt.Println("Underlying primes array:", primes) // Output: [2, 99, 5, 7, 11] (Notice 3 changed to 99)

	// 3. Declaring a slice directly (Note: NO size inside brackets [])
	dynamicSlice := []int{100, 200, 300}
	fmt.Println("Direct slice:", dynamicSlice)

	// 4. Growing a slice dynamically using append()
	// If the capacity is exceeded, Go handles reallocation behind the scenes.
	dynamicSlice = append(dynamicSlice, 400, 500)
	fmt.Println("Expanded slice:", dynamicSlice) // Output: [100, 200, 300, 400, 500]

	// 5. Checking length vs capacity
	// len() = number of elements currently in the slice
	// cap() = max number of elements the slice can hold before resizing
	fmt.Printf("Len: %d, Cap: %d\n", len(dynamicSlice), cap(dynamicSlice))

	// 6. Creating a slice efficiently using make()
	// Syntax: make([]Type, length, capacity)
	preAllocatedSlice := make([]int, 3, 10)                   // Length 3, Capacity 10
	fmt.Println("Make slice zero-values:", preAllocatedSlice) // Output: [0 0 0]

	// -------------------------------------------------------
	// efficient slice growth example
	// -------------------------------------------------------
	// 1. Initial State: Length 3, Capacity 10
	// The first 3 elements are initialized to 0.
	// Elements 4 through 10 are allocated in memory but hidden from access.
	slice := make([]int, 3, 10)
	fmt.Printf("Initial: len=%d, cap=%d, %v\n", len(slice), cap(slice), slice)
	// Output: Initial: len=3, cap=10, [0 0 0]

	// 2. Add elements within the pre-allocated capacity (Highly Efficient!)
	// Go does NOT allocate new memory here. It just puts 40 and 50 into
	// the reserved hidden slots and updates the internal length tracker.
	slice = append(slice, 40, 50)
	fmt.Printf("After appending within cap: len=%d, cap=%d, %v\n", len(slice), cap(slice), slice)
	// Output: After appending within cap: len=5, cap=10, [0 0 0 40 50]

	// 3. Exceeding the pre-allocated capacity (Dynamic Resizing)
	// Let's add 6 more items. Total items will be 11, which exceeds our cap of 10.
	// Go will silently handle this behind the scenes.
	slice = append(slice, 60, 70, 80, 90, 100, 110)
	fmt.Printf("Exceeded capacity: len=%d, cap=%d, %v\n", len(slice), cap(slice), slice)
	// Output: Exceeded capacity: len=11, cap=20, [0 0 0 40 50 60 70 80 90 100 110]
}
