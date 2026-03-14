package tests

import (
	"testing"
)

func testAdd(t *testing.T) {
	result := Add(2, 3) // use table driven testing, so that you no need to write multiple test functions

	if result != 5 {
		t.Errorf("Expected 5 but got %d", result)
	}
}
