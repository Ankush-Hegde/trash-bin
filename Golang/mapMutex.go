package main

import (
	"fmt"
	"sync"
)

type SafeMap struct {
	mu   sync.RWMutex // RWMutex, For maps with a high frequency of read operations
	data map[string]int
}

func NewSafeMap() *SafeMap {
	return &SafeMap{
		data: make(map[string]int),
	}
}

func (s *SafeMap) Set(key string, value int) {
	s.mu.Lock()
	defer s.mu.Unlock()
	s.data[key] = value
}

func (s *SafeMap) Get(key string) (int, bool) {
	s.mu.RLock()
	defer s.mu.RUnlock()
	val, exists := s.data[key]
	return val, exists
}

func (s *SafeMap) Delete(key string) {
	s.mu.Lock()
	defer s.mu.Unlock()
	delete(s.data, key)
}

func RWMutexfunction() {
	safeMap := NewSafeMap()
	var wg sync.WaitGroup

	// Set values concurrently
	for i := 0; i < 10; i++ {
		wg.Add(1)
		go func(i int) {
			defer wg.Done()
			key := fmt.Sprintf("key%d", i)
			safeMap.Set(key, i)
		}(i)
	}

	// Get values concurrently
	for i := 0; i < 10; i++ {
		wg.Add(1)
		go func(i int) {
			defer wg.Done()
			key := fmt.Sprintf("key%d", i)
			if val, exists := safeMap.Get(key); exists {
				fmt.Printf("Key: %s, Value: %d\n", key, val)
			} else {
				fmt.Printf("Key: %s does not exist\n", key)
			}
		}(i)
	}

	// Wait for all goroutines to finish
	wg.Wait()

	// Print final map state
	fmt.Println("Final map state:")
	for i := 0; i < 10; i++ {
		key := fmt.Sprintf("key%d", i)
		if val, exists := safeMap.Get(key); exists {
			fmt.Printf("Key: %s, Value: %d\n", key, val)
		}
	}
}
