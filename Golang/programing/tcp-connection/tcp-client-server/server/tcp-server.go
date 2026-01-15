package main

import (
	"bufio"
	"fmt"
	"net"
)

func main() {

	// 1️⃣ Start listening on TCP port 9000
	// net.Listen creates a TCP socket and binds it to the address
	listener, err := net.Listen("tcp", ":9000")
	if err != nil {
		panic(err)
	}
	defer listener.Close()

	fmt.Println("TCP Server listening on port 9000")

	for {
		// 2️⃣ Accept waits (BLOCKS) until a client connects
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Error accepting connection:", err)
			continue
		}

		fmt.Println("Client connected:", conn.RemoteAddr())

		// 3️⃣ Handle many client connection concurrently
		go handleClient(conn)
	}
}

func handleClient(conn net.Conn) {
	// Ensure connection closes when function exits
	defer conn.Close()

	// 4️⃣ Create a buffered reader to read incoming data
	reader := bufio.NewReader(conn)

	for {
		// 5️⃣ Read data until newline '\n'
		// TCP is a stream, not message-based
		message, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println("Client disconnected:", conn.RemoteAddr())
			return
		}

		fmt.Printf("Received from %s: %s", conn.RemoteAddr(), message)

		// 6️⃣ Send response back to client
		response := "received" + message
		conn.Write([]byte(response))
	}
}
