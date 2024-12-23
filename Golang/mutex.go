package main

import (
	"fmt"
	"sync"
)

// Shared counter and Mutex
var counter int
var mutex sync.Mutex // mutual exclusion

func increment(wg *sync.WaitGroup) {
	defer wg.Done() // Decrements the WaitGroup counter when the goroutine finishes

	for i := 0; i < 1000; i++ {
		mutex.Lock()   // Acquire the lock
		counter++      // Critical section: increment the counter
		mutex.Unlock() // Release the lock
	}
}

func functionformutex() {
	var wg sync.WaitGroup
	numGoroutines := 10

	// Launch multiple goroutines
	for i := 0; i < numGoroutines; i++ {
		wg.Add(1)
		go increment(&wg)
	}

	wg.Wait() // Wait for all goroutines to finish

	fmt.Println("Final Counter:", counter)
}
