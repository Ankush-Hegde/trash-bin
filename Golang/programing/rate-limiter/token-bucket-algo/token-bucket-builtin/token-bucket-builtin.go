package main

// import (
// 	"fmt"
// 	"time"

// 	"golang.org/x/time/rate" // can be installed only in go.mod file
// )

// func main() {
// 	limiter := rate.NewLimiter(2, 5)
// 	// 2 events per second
// 	// burst capacity 5

// 	for i := 0; i < 10; i++ {
// 		if limiter.Allow() {
// 			fmt.Println("Allowed")
// 		} else {
// 			fmt.Println("Blocked")
// 		}
// 		time.Sleep(300 * time.Millisecond)
// 	}
// }
