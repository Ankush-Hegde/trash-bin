package main // always it must be main package

import (
	"encoding/json"
	"io"
	"net/http"
	"time"
)

func main() {
	println("starting the server in port :8080..")

	http.HandleFunc(
		"/health",
		func(w http.ResponseWriter, r *http.Request) {
			//////////////////////// simple one //////////////////

			w.WriteHeader(http.StatusOK)
			// w.Write([]byte("success")) // write body

			/////////////////////////////////////////////////////

			//////////////////// create data ////////////////////////
			data := map[string]interface{}{
				"message": "this is the message",
				"status":  "success",
			}
			///////////////////////////////////////////////////////

			json.NewEncoder(w).Encode(data) // create a json body
		},
	)

	http.HandleFunc("/v1/echo", func(w http.ResponseWriter, r *http.Request) {

		if r.Method != http.MethodPost {
			http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
			return
		}

		data, err := io.ReadAll(r.Body) // uses memory-> so in prod use limit or use streaming by io.copy
		if err != nil {
			http.Error(w, "Failed to read body", http.StatusBadRequest)
			return
		}
		defer r.Body.Close()

		var payload map[string]interface{}

		err = json.Unmarshal(data, &payload)
		if err != nil {
			http.Error(w, "Invalid JSON", http.StatusBadRequest)
			return
		}

		w.WriteHeader(http.StatusOK)
		json.NewEncoder(w).Encode(payload)

		// json.NewEncoder(w).Encode(data) // this is wrong it will return encoded string
	})

	http.HandleFunc("/v1/streaming", func(w http.ResponseWriter, r *http.Request) {

		/////////////////////////// this is streaming /////////////////////////////

		// data, err := io.Copy(w, r.Body)
		// if err != nil {
		// 	http.Error(w, "Failed to read body", http.StatusBadRequest)
		// 	return
		// }
		// defer r.Body.Close()

		//////////////////////////////////////////////////////////////////////////

		flusher, ok := w.(http.Flusher)
		if !ok {
			http.Error(w, "Streaming not supported", http.StatusInternalServerError)
			return
		}
		encoder := json.NewEncoder(w)

		for i := 0; i < 5; i++ {
			encoder.Encode(map[string]int{"count": i})
			flusher.Flush() // FORCE SEND use ```curl -N http://localhost:8080/v1/streaming``` to see streaming

			time.Sleep(time.Second)
		}
	})

	http.ListenAndServe(":8080", nil) // open port
}
