APP=myservice

.PHONY: build run test lint docker docs

build:
	go build -o bin/$(APP) cmd/server/main.go

run:
	go run cmd/server/main.go

test:
	go test ./...

lint:
	golangci-lint run

docs:
	swag init

docker:
	docker build -t $(APP) .

clean:
	rm -rf bin