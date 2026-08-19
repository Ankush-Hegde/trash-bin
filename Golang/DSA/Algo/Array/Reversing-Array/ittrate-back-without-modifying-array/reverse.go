package main

import "fmt"

func main() {
	colors := []string{"red", "green", "blue"}

	// Start at the last index and count down to 0
	for i := len(colors) - 1; i >= 0; i-- {
		fmt.Println(colors[i])
	}
}
