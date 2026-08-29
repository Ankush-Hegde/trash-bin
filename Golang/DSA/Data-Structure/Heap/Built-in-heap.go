// remember min heap parent are smaller than child,
// max heap parents are larger or equal to child,
// it dosen't hold rule like binary tree that right child must be larger or smaller
package main

import (
	"container/heap"
	"fmt"
)

// IntHeap represents a slice of integers
type IntHeap []int

// ---------------------------------------------------------
// 1. sort.Interface implementation
// ---------------------------------------------------------
func (h IntHeap) Len() int {
	return len(h)
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

// Less controls whether the heap is a Min-Heap (<) or Max-Heap (>)
// Change this single operator to switch heap behavior.
func (h IntHeap) Less(i, j int) bool {
	return h[i] < h[j] // Min-Heap (use > for Max-Heap)
}

// ---------------------------------------------------------
// 2. heap.Interface implementation (Push and Pop modify the underlying pointer)
// ---------------------------------------------------------
func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

// Pop removes and returns the last item of the slice
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	// --- Min-Heap Demonstration ---
	minH := &IntHeap{5, 2, 6, 3, 1}

	// 1. heap.Init: Establishes the heap invariant in O(n) time
	heap.Init(minH)
	fmt.Printf("Min-Heap Initialized Root (Minimum): %d\n", (*minH)[0])

	// 2. heap.Push: Adds an element and re-establishes the heap property
	heap.Push(minH, 0)
	fmt.Printf("Min-Heap after pushing 0, New Root: %d\n", (*minH)[0])

	// Peek at an arbitrary index (e.g., checking element stability or contents)
	fmt.Printf("Element at index 2: %d\n", (*minH)[2])

	// 3. heap.Remove: Deletes an element at a specific arbitrary index i
	// Removing index 1 (removes element and restores heap order)
	removed := heap.Remove(minH, 1)
	fmt.Printf("Removed element at index 1: %v\n", removed)

	// 4. heap.Pop: Removes and returns the root element iteratively (priority order)
	fmt.Print("Popping all elements from Min-Heap: ")
	for minH.Len() > 0 {
		fmt.Printf("%d ", heap.Pop(minH))
	}
	fmt.Println("")

	// --- Max-Heap Demonstration ---
	// Note: To make this a strict Max-Heap without changing methods dynamically,
	// update Less to `h[i] > h[j]`. For demonstration purposes using the current code,
	// imagine the Less function is configured as `h[i] > h[j]`.
	maxH := &IntHeap{2, 9, 3}

	// If Less uses `>`, heap.Init organizes the largest element to index 0
	heap.Init(maxH)
	fmt.Printf("Max-Heap Initialized Root (Maximum): %d\n", (*maxH)[0])

	heap.Push(maxH, 15)
	fmt.Printf("Max-Heap after pushing 15, New Root: %d\n", (*maxH)[0])

	fmt.Print("Popping all elements from Max-Heap: ")
	for maxH.Len() > 0 {
		fmt.Printf("%d ", heap.Pop(maxH))
	}
	fmt.Println()
}
