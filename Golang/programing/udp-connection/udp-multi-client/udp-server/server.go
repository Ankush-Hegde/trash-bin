package main

import (
	"fmt"
	"net"
)

func main() {
	addr := net.UDPAddr{
		Port: 9000,
		IP:   net.ParseIP("0.0.0.0"),
	}

	conn, err := net.ListenUDP("udp", &addr)
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	fmt.Println("UDP chat server running on :9000")

	clients := make(map[string]*net.UDPAddr)

	buffer := make([]byte, 1024)

	for {
		n, clientAddr, err := conn.ReadFromUDP(buffer)
		if err != nil {
			continue
		}

		msg := string(buffer[:n])
		fmt.Printf("Received from %s: %s", clientAddr, msg)

		// Register client
		clients[clientAddr.String()] = clientAddr

		// Broadcast
		for _, addr := range clients {
			if addr.String() != clientAddr.String() {
				conn.WriteToUDP([]byte(msg), addr)
			}
		}
	}
}
