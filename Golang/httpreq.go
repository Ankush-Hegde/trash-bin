// 7. Handling HTTP Requests
// Question:
// Write a Go HTTP server with two endpoints:

// GET /ping - Returns "pong".
// POST /square - Accepts a JSON payload like {"number": 4} and returns the square of the number.
// Ensure clean error handling and struct validation

package main

import (
	"encoding/json"
	"fmt"
	"net/http"
	"strconv"
)

// Payload represents the input JSON structure for the POST /square endpoint
type Payload struct {
	Number int `json:"number"`
}

// Response represents the JSON response structure
type Response struct {
	Result int `json:"result"`
}

func mainn() {
	http.HandleFunc("/ping", pingHandler)
	http.HandleFunc("/square", squareHandler)

	fmt.Println("Starting server on :8080...")
	if err := http.ListenAndServe(":8080", nil); err != nil {
		fmt.Println("Error starting server:", err)
	}
}

// pingHandler handles the GET /ping endpoint
func pingHandler(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodGet {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
		return
	}
	w.WriteHeader(http.StatusOK)
	w.Write([]byte("pong"))
}

// squareHandler handles the POST /square endpoint
func squareHandler(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
		return
	}

	var payload Payload
	decoder := json.NewDecoder(r.Body)
	err := decoder.Decode(&payload)
	if err != nil {
		http.Error(w, "Invalid JSON payload", http.StatusBadRequest)
		return
	}

	if payload.Number == 0 && strconv.Itoa(payload.Number) == "" {
		http.Error(w, "Invalid input: 'number' is required and must be non-zero", http.StatusBadRequest)
		return
	}

	// Compute the square
	result := payload.Number * payload.Number

	// Create a response and send it back
	response := Response{Result: result}
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}
