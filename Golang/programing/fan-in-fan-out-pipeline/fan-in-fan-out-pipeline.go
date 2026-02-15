package main

import (
	"fmt"
	"sync"
)

// -------------------------
// Stage 1 Worker
// -------------------------
func squareWorker(
	jobs <-chan int,
	out chan<- struct {
		original int
		square   int
	},
	wg *sync.WaitGroup,
) {
	defer wg.Done()

	for num := range jobs {

		result := struct {
			original int
			square   int
		}{
			original: num,
			square:   num * num,
		}

		// -------------------------
		// 🔥 FAN-IN HAPPENS HERE
		// Multiple square workers
		// are sending results into
		// the SAME channel (stage1Out)
		// -------------------------
		out <- result
	}
}

// -------------------------
// Stage 2 Worker
// -------------------------
func addWorker(
	in <-chan struct {
		original int
		square   int
	},
	wg *sync.WaitGroup,
) {
	defer wg.Done()

	for data := range in {
		sum := data.original + data.square
		fmt.Printf("Original: %d, Square: %d, Sum: %d\n",
			data.original, data.square, sum)
	}
}

func main() {

	input := make(chan int)

	stage1Out := make(chan struct {
		original int
		square   int
	})

	// --------------------------------
	// 🔥 FAN-OUT (Stage 1)
	// 1 input channel -> 2 square workers
	// --------------------------------
	var wg1 sync.WaitGroup
	for i := 0; i < 2; i++ {
		wg1.Add(1)
		go squareWorker(input, stage1Out, &wg1)
	}

	// Close stage1Out AFTER all square workers finish
	go func() {
		wg1.Wait()
		close(stage1Out)
	}()

	// --------------------------------
	// 🔥 FAN-OUT (Stage 2)
	// 1 stage1Out channel -> 2 add workers
	// --------------------------------
	var wg2 sync.WaitGroup
	for i := 0; i < 2; i++ {
		wg2.Add(1)
		go addWorker(stage1Out, &wg2)
	}

	// Send input
	go func() {
		nums := []int{1, 2, 3, 4, 5}
		for _, n := range nums {
			input <- n
		}
		close(input)
	}()

	wg2.Wait()
}
