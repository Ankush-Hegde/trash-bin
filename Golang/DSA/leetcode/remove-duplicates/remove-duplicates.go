package main

import (
	"fmt"
)

func removeDuplicatesKeepLast(sentence string) string {
	charIndex := make(map[rune]int) // Map to store last occurrence index
	chars := []rune(sentence)

	// Store the last occurrence index of each character
	for i, char := range chars {
		charIndex[char] = i
		fmt.Printf("%d %c %c\n", i, char, chars)
	}

	// Reconstruct string by keeping only characters at their last index
	var result []rune
	for i, char := range chars {
		if charIndex[char] == i {
			result = append(result, char)
			fmt.Println(string(result))
		} else {
			fmt.Println("skip")
		}
	}

	return string(result)
}

func main() {
	sentence := "geeksforgeeks"
	fmt.Println(removeDuplicatesKeepLast(sentence)) // Output: "forgeks"
}
