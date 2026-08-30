package main

import (
	"container/heap"
	"fmt"
)

// this should not be "var Maxheap []int"
// since we are using it as receiver in func like Less, Push, Pop etc
type Maxheap []int

//------------------------------------- built-in sort.Interface ---------------------------------------

// The sorting and heap algorithms rely strictly on true/false answers to compare items,
// decide whether to swap parent and child nodes during sift-up and sift-down operations,
//
//	and correctly balance the tree
func (h Maxheap) Less(i, j int) bool {
	return h[i] > h[j]
}

// Why it's needed: The heap algorithms (sift-up, sift-down, and tree calculations) frequently need to
// know the current number of elements in the slice to find parent-child index relationships
// and determine when the heap is empty.
func (h Maxheap) Len() int {
	return len(h)
}

// Why it's needed: Whenever sift-up or sift-down determines that a parent and child are out of order
// (for instance, a smaller value is sitting below a larger value in a max-heap), they must physically
// trade places to fix the tree structure
func (h Maxheap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

//------------------------------------------------------------------------------------------------------

// --------------------------------- container/heap package's internal interface -----------------------
func (h *Maxheap) Push(i any) {
	*h = append(*h, i.(int))
}

func (h *Maxheap) Pop() any { // always the receiver must Maxheap pointer else you may stuck in loop
	old := *h
	n := len(old)
	val := old[n-1]
	*h = old[0 : n-1]
	return val
}

// ------------------------------------------------------------------------------------------------------
func main() {
	arr := Maxheap{7, 2, 1, 6, 9} // use the custom type

	heap.Init(&arr) // heapify() -> time-complexity o(n)

	// this calls container/heap.Push(arg1, arg2),
	// which internally calls arg1.Push(any) which is Push(any) in this file
	heap.Push(&arr, 10)

	// if arr := &Maxheap{7, 2, 1, 6, 9}
	// then ```fmt.Printf("%d ", (*arr)[0])``` The parentheses explicitly tell Go:
	// "First dereference the pointer arr to get the actual underlying slice, and then look up index 0."
	fmt.Printf("%d ", arr[0])

	for arr.Len() > 0 {
		fmt.Printf("%d ", heap.Pop(&arr)) // pops from heap
	}
}
