package main

import (
	"encoding/json"
	"fmt"
)

// Person struct represents the data structure for demonstration
type Person struct {
	Name    string `json:"name"`
	Age     int    `json:"age"`
	Address string `json:"address"`
}

func main() {
	// Example struct
	person := Person{
		Name:    "Alice",
		Age:     30,
		Address: "123 Main St",
	}

	// Convert struct to JSON
	jsonData, err := structToJSON(person)
	if err != nil {
		fmt.Println("Error converting struct to JSON:", err)
		return
	}
	fmt.Println("Struct to JSON:", string(jsonData))

	// JSON payload (for demonstration)
	jsonPayload := `{"name": "Bob", "age": 25, "address": "456 Elm St"}`

	// Convert JSON to struct
	var newPerson Person
	err = jsonToStruct(jsonPayload, &newPerson)
	if err != nil {
		fmt.Println("Error converting JSON to struct:", err)
		return
	}
	fmt.Println("JSON to Struct:", newPerson)
}

// structToJSON converts a Go struct to JSON
func structToJSON(data interface{}) ([]byte, error) {
	// Marshal the struct to JSON
	return json.Marshal(data)
}

// jsonToStruct converts a JSON payload to a Go struct
func jsonToStruct(jsonData string, result interface{}) error {
	// Unmarshal the JSON data into the result
	return json.Unmarshal([]byte(jsonData), result)
}
