package main

import "fmt"

func sum(a int, b int, c chan int) {
	c <- a + b // Send the sum into the channel
}

func main() {
	c := make(chan int) // Create a channel

	go sum(2, 3, c) // Run goroutine
	result := <-c   // Receive data from the channel
	fmt.Println("Result:", result)
}
