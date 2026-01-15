package main

import (
	"bufio"
	"fmt"
	"io"
	"net"
	"os"
)

func main() {
	//////////////////////////// create connection /////////////////////
	conn, err := net.Dial("tcp", "localhost:9000")
	if err != nil {
		print("error establishing the tcp connection")
		panic(err)
	}
	defer conn.Close() // use to free resources if program crashes

	println("connected to the server")
	///////////////////////////////////////////////////////////////////

	/////////////////// read from server //////////////////////

	done := make(chan struct{}) // used to exit program safly

	go func() {
		reader := bufio.NewReader(conn)

		for {
			msg, err := reader.ReadString('\n')
			if err != nil {
				print("connection lost")
				close(done) // dont use os.exit it will not free up the resources but exits the program
				return
			}
			print(msg)
		}
	}()

	//////////////////////////////////////////////////////////////////

	/////////////////////////// write to server /////////////////////
	go func() {
		input := bufio.NewReader(os.Stdin)
		for {
			text, err := input.ReadString('\n')
			if err != nil {
				if err == io.EOF {
					fmt.Println("Input closed, exiting")
					return
				}
				fmt.Println("Read error:", err)
				continue
			}

			_, err = conn.Write([]byte(text)) // errors are handled while writing to server
			if err != nil {
				fmt.Println("Write error:", err)
				return
			}
		}
	}()

	//////////////////////// any problem in reading close //////////////
	<-done
	fmt.Println("shutting down gracefully")
}
