package main

import (
	"fmt"
	"time"
)

type LeakyBucket struct {
	queue chan int
}

func NewLeakyBucket(capacity int, leakRate time.Duration) *LeakyBucket {
	lb := &LeakyBucket{
		queue: make(chan int, capacity),
	}

	go func() {
		ticker := time.NewTicker(leakRate)
		for range ticker.C {
			select {
			case job := <-lb.queue:
				fmt.Println("Processed:", job)
			default:
			}
		}
	}()

	return lb
}

func (lb *LeakyBucket) Add(job int) bool {
	select {
	case lb.queue <- job:
		return true
	default:
		return false
	}
}

func main() {
	lb := NewLeakyBucket(5, 1*time.Second)

	for i := 0; i < 10; i++ {
		if lb.Add(i) {
			fmt.Println("Accepted:", i)
		} else {
			fmt.Println("Dropped:", i)
		}
		time.Sleep(200 * time.Millisecond)
	}

	time.Sleep(10 * time.Second)
}
