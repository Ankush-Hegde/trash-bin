package main

import "fmt"

func main() {
	// multidimensional arrays (arrays of arrays)
	// Declares a 2x3 integer matrix (2 rows, 3 columns)
	matrix := [2][3]int{
		{1, 2, 3},
		{4, 5, 6},
	}
	fmt.Println(matrix[1][2]) // Accesses row 1, column 2. Output: 6
}
