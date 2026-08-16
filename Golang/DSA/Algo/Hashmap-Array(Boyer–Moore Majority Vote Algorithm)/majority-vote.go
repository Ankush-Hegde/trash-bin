package main

import "fmt"

func majorityElement(nums []int) int {
	count := 0
	candid := 0
	// this is Boyer–Moore Majority Vote Algorithm
	// you can use hash map but that has higher space complexity

	for _, v := range nums {
		if count == 0 {
			candid = v
			count++
		} else if v == candid {
			count++
		} else if v != candid {
			count--
		}
	}
	return candid

}

func main() {
	nums := []int{2, 2, 1, 1, 1, 2, 2}
	result := majorityElement(nums)
	fmt.Printf("The majority element is: %d\n", result)
}
