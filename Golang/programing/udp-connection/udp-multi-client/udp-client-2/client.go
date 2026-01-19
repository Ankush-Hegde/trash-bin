package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
)

func main() {
	serverAddr, err := net.ResolveUDPAddr("udp", "localhost:9000")
	if err != nil {
		panic(err)
	}

	conn, err := net.DialUDP("udp", nil, serverAddr)
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	fmt.Println("Connected to UDP chat")

	// Receive messages
	go func() {
		buffer := make([]byte, 1024)
		for {
			n, _, err := conn.ReadFromUDP(buffer)
			if err != nil {
				return
			}
			fmt.Print(string(buffer[:n]))
		}
	}()

	// Send messages
	input := bufio.NewReader(os.Stdin)
	for {
		text, _ := input.ReadString('\n')
		conn.Write([]byte(text))
	}
}
