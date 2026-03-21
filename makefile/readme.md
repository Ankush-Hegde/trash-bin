What is a Makefile?

A Makefile is a file used by GNU Make to automate commands.

Think of it as:
```
command shortcuts + build automation
```
Instead of typing:
```
go build ./cmd/server
go test ./...
swag init
docker build .
```
You just run:
```
make build
make test
make docs
```

Example Makefile for Go Backend
```
APP_NAME=myapp

build:
	go build -o bin/$(APP_NAME) cmd/server/main.go

run:
	go run cmd/server/main.go

test:
	go test ./...

lint:
	golangci-lint run

clean:
	rm -rf bin
```
Usage:
```
make build
make run
make test
make clean
```

5️⃣ Variables in Makefile
```
APP=myservice
PORT=8080

run:
	go run main.go --port=$(PORT)
```
Run:
```
make run
```
6️⃣ Dependencies Between Tasks

Example:
```
build: test
	go build -o app main.go

test:
	go test ./...
```
Running:
```
make build
```

Automatically runs:
```
test → build
```

.PHONY => tells make file to run the command like build or anything even if the filesystem has a file named build