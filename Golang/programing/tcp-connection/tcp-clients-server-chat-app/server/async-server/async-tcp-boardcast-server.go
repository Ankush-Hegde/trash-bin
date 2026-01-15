package main

import (
	"bufio"
	"fmt"
	"net"
	"sync"
)

// Client represents a connected client
type Client struct {
	conn net.Conn
	send chan string // outgoing messages channel
	name string
}

// Global state
var (
	clients   = make(map[*Client]bool)
	broadcast = make(chan string)
	mu        sync.Mutex
)

func main() {
	listener, err := net.Listen("tcp", ":9000")
	if err != nil {
		panic(err)
	}
	defer listener.Close()

	fmt.Println("Async TCP broadcast server running on :9000")

	// Central broadcaster goroutine
	go broadcaster()

	for {
		conn, err := listener.Accept()
		if err != nil {
			continue
		}

		client := &Client{
			conn: conn,
			send: make(chan string, 10), // buffer prevents blocking
			name: conn.RemoteAddr().String(),
		}

		mu.Lock()
		clients[client] = true
		mu.Unlock()

		fmt.Println("Client connected:", client.name)

		// One goroutine for reading
		go handleRead(client)

		// One goroutine for writing
		go handleWrite(client)
	}
}

func handleRead(client *Client) {
	defer removeClient(client)

	reader := bufio.NewReader(client.conn)

	for {
		msg, err := reader.ReadString('\n')
		if err != nil {
			return
		}

		message := fmt.Sprintf("[%s]: %s", client.name, msg)

		// Send to broadcast channel (NON-BLOCKING)
		broadcast <- message
	}
}

func handleWrite(client *Client) {
	for msg := range client.send {
		_, err := client.conn.Write([]byte(msg))
		if err != nil {
			return
		}
	}
}

func broadcaster() {
	for msg := range broadcast {
		mu.Lock()
		for client := range clients {
			select {
			case client.send <- msg:
				// message queued successfully
			default:
				// non-blocking send with backpressure protection "there will be no blocking if we encounter slow or blocked client"
				// client's send buffer is full → drop message
				fmt.Println("Dropping message for:", client.name)
			}
		}
		mu.Unlock()
	}
}

func removeClient(client *Client) {
	mu.Lock()
	delete(clients, client)
	mu.Unlock()

	close(client.send)
	client.conn.Close()

	fmt.Println("Client disconnected:", client.name)
}
