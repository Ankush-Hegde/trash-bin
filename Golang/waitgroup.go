package main

import (
	"fmt"
	"sync"
)

func printMessage(msg string, wg *sync.WaitGroup) {
	defer wg.Done() // Decrement WaitGroup counter when finished
	for i := 0; i < 5; i++ {
		fmt.Println(msg, i)
	}
}

func notmain2() {
	var wg sync.WaitGroup

	wg.Add(2) // Add a goroutine to the WaitGroup
	defer fmt.Println("hello")

	go printMessage("Hello from Goroutine", &wg)
	go printMessage("Hello from Goroutine", &wg)
	fmt.Println("Hello, Go!")

	wg.Wait() // Wait for goroutines to complete
}
