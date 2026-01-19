package main

// Note: udp client can be ran before running udp server
// since client dosent need to do handshake like tcp client

import (
	"fmt"
	"net"
)

func main() {
	// Resolve server address
	serverAddr, err := net.ResolveUDPAddr("udp", "localhost:9000") // using net.Dial("udp", add) will not work for multiple client
	if err != nil {
		panic(err)
	}

	// Create UDP connection
	conn, err := net.DialUDP("udp", nil, serverAddr)
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	// Send message
	message := "Hello UDP Server"
	_, err = conn.Write([]byte(message))
	if err != nil {
		panic(err)
	}

	fmt.Println("Sent:", message)

	// Receive response
	buffer := make([]byte, 1024)
	n, _, err := conn.ReadFromUDP(buffer)
	if err != nil {
		panic(err)
	}

	fmt.Println("Received:", string(buffer[:n]))
}
