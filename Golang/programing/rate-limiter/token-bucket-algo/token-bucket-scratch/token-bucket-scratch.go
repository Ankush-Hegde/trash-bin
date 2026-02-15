package main

import (
	"fmt"
	"sync"
	"time"
)

type TokenBucket struct {
	capacity   int
	tokens     int
	refillRate int // tokens per second
	lastRefill time.Time
	mu         sync.Mutex
}

func NewTokenBucket(capacity, refillRate int) *TokenBucket {
	return &TokenBucket{
		capacity:   capacity,
		tokens:     capacity,
		refillRate: refillRate,
		lastRefill: time.Now(),
	}
}

func (tb *TokenBucket) Allow() bool {
	tb.mu.Lock()
	defer tb.mu.Unlock()

	now := time.Now()
	elapsed := now.Sub(tb.lastRefill).Seconds()

	refill := int(elapsed) * tb.refillRate
	if refill > 0 {
		tb.tokens += refill
		if tb.tokens > tb.capacity {
			tb.tokens = tb.capacity
		}
		tb.lastRefill = now
	}

	if tb.tokens > 0 {
		tb.tokens--
		return true
	}

	return false
}

func main() {
	tb := NewTokenBucket(5, 2) // capacity=5, refill 2/sec

	for i := 0; i < 10; i++ {
		if tb.Allow() {
			fmt.Println("Allowed")
		} else {
			fmt.Println("Blocked")
		}
		time.Sleep(300 * time.Millisecond)
	}
}
