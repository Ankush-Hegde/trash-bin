//Error Handling and Custom Errors
//Question:
//Write a function to divide two integers. If the denominator is zero, return a custom error
//using Go's errors package. The error message should include a custom error type and details about the invalid operation.

package main

import (
	"fmt"
)

// CustomError defines a custom error type with additional details
type CustomError struct {
	Operation string
	Details   string
}

func (e *CustomError) Error() string {
	return fmt.Sprintf("error in %s: %s", e.Operation, e.Details)
}

// Divide divides two integers and returns the result or a custom error if the denominator is zero
func Divide(numerator, denominator int) (int, error) {
	if denominator == 0 {
		// Return a custom error with details
		return 0, &CustomError{
			Operation: "Division",
			Details:   "denominator cannot be zero",
		}
	}
	return numerator / denominator, nil
}

func mainsss() {
	// Test cases
	results := []struct {
		numerator   int
		denominator int
	}{
		{10, 2},  // Valid division
		{5, 0},   // Invalid division (zero denominator)
		{15, -3}, // Valid division
	}

	for _, test := range results {
		result, err := Divide(test.numerator, test.denominator)
		if err != nil {
			fmt.Printf("Error: %s\n", err)
		} else {
			fmt.Printf("Result of %d / %d = %d\n", test.numerator, test.denominator, result)
		}
	}
}
