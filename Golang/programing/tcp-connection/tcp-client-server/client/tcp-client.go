package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
)

func main() {

	// 1️⃣ Connect to TCP server
	// net.Dial creates a TCP connection to the server
	conn, err := net.Dial("tcp", "localhost:9000")
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	fmt.Println("Connected to TCP server")

	// 2️⃣ Read input from terminal (stdin)
	inputReader := bufio.NewReader(os.Stdin)

	// 3️⃣ Reader for server responses
	serverReader := bufio.NewReader(conn)

	for {
		fmt.Print("Enter message: ")

		// 4️⃣ Read user input until newline
		text, _ := inputReader.ReadString('\n')

		// 5️⃣ Send message to server
		conn.Write([]byte(text))

		// 6️⃣ Read server response
		response, err := serverReader.ReadString('\n') // `"\n" is used to detect the msg ends` or else we can use content length
		if err != nil {
			fmt.Println("Server closed connection")
			return
		}

		fmt.Print("Response from server: ", response)
	}
}
