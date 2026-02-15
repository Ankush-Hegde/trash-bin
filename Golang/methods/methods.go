package main

import (
	"fmt"
	"math"
)

type Vertex struct {
	X, Y float64
}

// method can be defined with pointer like *vertex.
// refer this doc https://go.dev/tour/methods/7
// https://go.dev/tour/methods/9
func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
	v := Vertex{3, 4}
	fmt.Println(v.Abs())
}
