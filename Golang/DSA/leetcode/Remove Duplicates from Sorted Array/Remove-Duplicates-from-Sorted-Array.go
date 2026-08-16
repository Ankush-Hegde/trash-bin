package main

import (
	"fmt"
	"slices"
)

func removeDuplicates(nums []int) int {
	uniqueVal := make(map[int]int)
	newArr := []int{}

	for _, v := range nums {
		if uniqueVal[v] == 0 {
			uniqueVal[v] = v
		}
	}
	for _, v := range uniqueVal {
		newArr = append(newArr, v)
	}

	slices.Sort(newArr)
	copy(nums[:], newArr[:])

	return len(uniqueVal)
}

func main() {
	nums := []int{1, 1, 2, 3, 3, 4}
	k := removeDuplicates(nums)
	fmt.Printf("Number of unique elements: %d\n", k)
	fmt.Printf("Modified array: %v\n", nums[:k])
}
