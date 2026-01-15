package main

import (
	"fmt"
	"sync"
)

func itt(s string, w *sync.WaitGroup) {
	defer w.Done()

	for i := 0; i < 5; i++ {
		fmt.Println(s)
	}
}

func maint() {
	var weightGroup sync.WaitGroup

	weightGroup.Add(1)
	go itt("first", &weightGroup)

	weightGroup.Add(1)
	go itt("second", &weightGroup)

	weightGroup.Wait()
}
