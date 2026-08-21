package main

import "fmt"

type Node struct {
	data int
	next *Node
}

func main() {
	LinkedList := &Node{data: 1, next: nil}

	fmt.Println(LinkedList.data) // Output: 1

	return
}
