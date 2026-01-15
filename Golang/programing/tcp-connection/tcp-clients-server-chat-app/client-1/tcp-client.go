package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
)

func main() {

	// 1️⃣ Connect to server
	conn, err := net.Dial("tcp", "localhost:9000")
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	fmt.Println("Connected to broadcast server")

	// 2️⃣ Goroutine to receive messages
	go func() {
		reader := bufio.NewReader(conn)
		for {
			msg, err := reader.ReadString('\n')
			if err != nil {
				fmt.Println("Disconnected from server")
				os.Exit(0)
			}
			fmt.Print(msg)
		}
	}()

	// 3️⃣ Send messages from stdin
	input := bufio.NewReader(os.Stdin)

	for {
		text, _ := input.ReadString('\n')
		conn.Write([]byte(text))
	}
}
