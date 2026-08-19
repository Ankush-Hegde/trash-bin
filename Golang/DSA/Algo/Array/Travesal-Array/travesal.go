package main

import "fmt"

func main() {
	names := [3]string{"Alice", "Bob", "Charlie"}
	nums := [4]int{10, 20, 30, 40}
	colors := [3]string{"Red", "Green", "Blue"}

	// Using for range (Gets both Index and Value)
	for index, value := range names {
		fmt.Printf("Index: %d, Value: %s\n", index, value)
	}

	// Using for range with a Blank Identifier (Value Only)
	for _, val := range nums {
		fmt.Println(val)
	}

	// Using for range with a Blank Identifier (Index Only)
	for index, _ := range nums {
		fmt.Println(index)
	}

	//  Using a Traditional Counter-Based Loop
	for i := 0; i < len(colors); i++ {
		fmt.Printf("Color at index %d is %s\n", i, colors[i])
	}

	// Efficient: Iterates over a pointer, preventing data copying
	// When using for _, v := range array, Go creates a temporary
	// copy of each item. If you are working with large arrays or structs,
	//  you can prevent copying and optimize performance by
	// passing a pointer to the array or using just the index
	for _, val := range &colors {
		_ = val
	}
}
