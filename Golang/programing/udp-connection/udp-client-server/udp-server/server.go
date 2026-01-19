package main

import (
	"fmt"
	"net"
)

func main() {
	// Resolve address
	addr, err := net.ResolveUDPAddr("udp", ":9000")
	if err != nil {
		panic(err)
	}

	// Listen on UDP
	conn, err := net.ListenUDP("udp", addr)
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	fmt.Println("UDP server listening on :9000")

	buffer := make([]byte, 1024)

	for {
		// Read packet
		n, clientAddr, err := conn.ReadFromUDP(buffer)
		if err != nil {
			fmt.Println("Read error:", err)
			continue
		}

		msg := string(buffer[:n])
		fmt.Printf("Received from %s: %s\n", clientAddr, msg)

		// Respond
		response := "ACK: " + msg
		_, err = conn.WriteToUDP([]byte(response), clientAddr)
		if err != nil {
			fmt.Println("Write error:", err)
		}
	}
}
