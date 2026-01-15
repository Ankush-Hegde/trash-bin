package main

// pass value from one channel to another
func main() {
	print("started")
	channel := make(chan int, 10)

	for i := 0; i < 10; i++ {
		channel <- i
	}

	modchannel := make(chan int, 10)

	for i := 0; i < 10; i++ {
		data := <-channel
		modchannel <- data * 2
	}

	close(modchannel)
	for value := range modchannel {
		print(value)
	}

	// for i := 0; i < 10; i++ {
	// 	print(<-modchannel)
	// }
}
