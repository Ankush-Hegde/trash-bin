package main

import (
	"bufio"
	"fmt"
	"net"
	"sync"
)

// Client represents one connected TCP client
type Client struct {
	conn net.Conn
	name string
}

// Global list of connected clients
var (
	clients = make(map[net.Conn]Client)
	mu      sync.Mutex // protects clients map
)

func main() {

	// 1️⃣ Start TCP server
	listener, err := net.Listen("tcp", ":9000")
	if err != nil {
		panic(err)
	}
	defer listener.Close()

	fmt.Println("Broadcast TCP server running on :9000")

	for {
		// 2️⃣ Accept new client
		conn, err := listener.Accept()
		if err != nil {
			continue
		}

		// 3️⃣ Register client
		client := Client{
			conn: conn,
			name: conn.RemoteAddr().String(),
		}

		mu.Lock()
		clients[conn] = client
		mu.Unlock()

		fmt.Println("Client connected:", client.name)

		// 4️⃣ Handle client concurrently
		go handleClient(client)
	}
}

func handleClient(client Client) {
	defer func() {
		// Remove client on disconnect
		mu.Lock()
		delete(clients, client.conn)
		mu.Unlock()

		client.conn.Close()
		fmt.Println("Client disconnected:", client.name)
	}()

	reader := bufio.NewReader(client.conn)

	for {
		// 5️⃣ Read message from client
		msg, err := reader.ReadString('\n')
		if err != nil {
			return
		}

		message := fmt.Sprintf("[%s]: %s", client.name, msg)

		// 6️⃣ Broadcast to ALL clients
		broadcast(message)
	}
}

func broadcast(message string) {
	mu.Lock()
	defer mu.Unlock()

	for _, client := range clients {
		client.conn.Write([]byte(message)) // msg is sent to client one by one it is sync request (if msg delays in one client it blocks whole server)
	}
}
