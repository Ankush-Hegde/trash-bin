// quine is a concept in computer programming where a program takes no input and produces a copy of its own source code as its only output.
//
//	This is an example of a quine written in Go.

package main

import "fmt"

func main() {
	q := `package main

import "fmt"

func main() {
	q := %q
	fmt.Printf(q, q)
}`
	fmt.Printf(q, q)
}
