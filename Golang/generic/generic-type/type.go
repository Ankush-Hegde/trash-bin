package main

import "fmt"

type List[T any] struct {
	next *List[T]
	val  T
}

func (l *List[T]) Push(val T) {
	newNode := &List[T]{val: val}
	newNode.next = l.next
	l.next = newNode
}

func (l *List[T]) Print() {
	for node := l.next; node != nil; node = node.next {
		fmt.Println(node.val)
	}
}

func main() {
	var list List[int]

	list.Push(10)
	list.Push(20)
	list.Push(30)

	list.Print()
}
