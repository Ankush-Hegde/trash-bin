// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

package main

import "fmt"

func returnLongComPrefix(arr []string) string {
	// size := 2

	shortestStringLength := 2 //i will take it directly for now

	for i := 0; i < shortestStringLength; i++ {

	}
	return "e"
}

func mainsssss() {
	arr1 := make([]string, 2)
	arr1[0] = "flower"
	arr1[1] = "flow"
	arr1[2] = "flight"

	arr2 := make([]string, 2)
	arr2[0] = "dog"
	arr2[1] = "racecar"
	arr2[2] = "car"

	LongPrefixOfArr1 := returnLongComPrefix(arr1)
	LongPrefixOfArr2 := returnLongComPrefix(arr2)

	fmt.Println("arr1 %d", LongPrefixOfArr1)
	fmt.Println("arr2 %d", LongPrefixOfArr2)
}
