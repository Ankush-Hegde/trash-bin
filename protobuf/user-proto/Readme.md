# this is the user-proto example in go

-> grpc server // has server code, run this to hit in kreya.
-> user // generated pb file
-> user-grpc-test // kreya collection
-> user-proto // contains proto file


// to create go.mod files
go mod init user-proto
go get google.golang.org/grpc
go get google.golang.org/protobuf
go mod tidy