package main

import (
	"fmt"
	"time"
)

func printMessage1(msg string) {
	for i := 0; i < 5; i++ {
		fmt.Println(msg, i)
		time.Sleep(100 * time.Millisecond)
	}
}

func notmain() {
	defer fmt.Println("hello")               // executes last, due to its LIFO, used in closing db connection and closing file
	go printMessage1("Hello from Goroutine") // here main function ends before go routin ends, use sync or time to keep the goroutine running
	// printMessage("Hello from Main")
	fmt.Println("Hello, Go!")
}
