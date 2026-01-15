package main

import "fmt"

//Write a function to merge two sorted arrays into a single sorted array.

func main() {
	var arr1 = []int{3, 5, 10, 11}
	var arr2 = []int{1, 2, 4, 6}
	var result = []int{}

	lenArr1 := len(arr1)
	lenArr2 := len(arr2)

	index := 0
	arr1Index := index
	arr2Index := index

	for arr1Index < lenArr1 && arr2Index < lenArr2 {
		if arr1[arr1Index] < arr2[arr2Index] {
			result = append(result, arr1[arr1Index])
			arr1Index++
		} else if arr1[arr1Index] > arr2[arr2Index] {
			result = append(result, arr2[arr2Index])
			arr2Index++
		} else {
			result = append(result, arr1[arr1Index])
			arr1Index++
			arr2Index++
		}
	}

	if arr1Index < lenArr1 {
		for arr1Index < lenArr1 {
			result = append(result, arr1[arr1Index])
			arr1Index++
		}
	} else {
		for arr2Index < lenArr2 {
			result = append(result, arr2[arr2Index])
			arr2Index++
		}
	}

	fmt.Println(result)

	// for index = 0; index < max(lenArr1, lenArr2); index++ {
	// 	if arr1[arr1Index] < arr2[arr2Index] {
	// 		result = append(result, arr1[arr1Index]) // append to result
	// 		arr1Index++
	// 	} else if arr1[arr1Index] > arr2[arr2Index] {
	// 		result = append(result, arr2[arr2Index]) // append to result
	// 		arr2Index++
	// 	} else {
	// 		result = append(result, arr1[arr1Index]) // append to result
	// 		arr1Index++
	// 		arr2Index++
	// 	}
	// }

	// // print result array
	// for index := 0; index < len(result); index++ {
	// 	println(result[index])
	// }
	// arr1 := []uint{}

	// arr1 = append(arr1, 1)

	// arr1 = append(arr1, 2)

	// arr1 = append(arr1, 3)

}
