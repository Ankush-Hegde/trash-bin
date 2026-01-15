package main

import "fmt"

func main() {
	c := make(chan int, 2) // Buffered channel with capacity 2

	c <- 10
	c <- 20

	fmt.Println(<-c) // Output: 10
	fmt.Println(<-c) // Output: 20
}
