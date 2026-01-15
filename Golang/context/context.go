// Context and Timeout
// Question:
// Write a function that executes a task (simulated with time.Sleep) but cancels the execution if it runs for more than 2 seconds.
// Use Go's context package to implement this.
package main

import (
	"context"
	"fmt"
	"time"
)

// Simulated long-running task
func longRunningTask(ctx context.Context) {
	select {
	case <-time.After(3 * time.Second): // Simulate a 3-second task
		fmt.Println("Task completed")
	case <-ctx.Done(): // Task canceled
		fmt.Println("Task canceled:", ctx.Err())
	}
}

func main() {
	// Create a context with a 2-second timeout
	ctx, cancel := context.WithTimeout(context.Background(), 2*time.Second) // increase to more than 3 sec for task to complet
	defer cancel()                                                          // Ensure resources are released

	fmt.Println("Starting task...")
	longRunningTask(ctx)
	fmt.Println("Program finished")
}
