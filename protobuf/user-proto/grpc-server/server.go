package main

import (
	"context"
	"log"
	"net"
	"time"

	userpb "user-proto/user"

	"google.golang.org/grpc"
	"google.golang.org/protobuf/types/known/timestamppb"
)

type UserServer struct {
	userpb.UnimplementedUserServiceServer
}

func (s *UserServer) GetUser(
	ctx context.Context,
	req *userpb.GetUserRequest,
) (*userpb.GetUserResponse, error) {

	log.Println("GetUser called with user_id:", req.UserId)

	email := "alice@example.com"

	return &userpb.GetUserResponse{
		User: &userpb.User{
			Id:    req.UserId,
			Name:  "Alice",
			Email: &email, // optional string → pointer
			Address: &userpb.Address{
				City:    "Mumbai",
				Country: "India",
			},
			Favorites: []string{"apple", "banana"},
			Role:      userpb.Role_ROLE_USER,
			CreatedAt: timestamppb.New(time.Now()),
		},
	}, nil
}

func main() {
	lis, err := net.Listen("tcp", ":50051")
	if err != nil {
		log.Fatal(err)
	}

	grpcServer := grpc.NewServer()
	userpb.RegisterUserServiceServer(grpcServer, &UserServer{})

	log.Println("🚀 gRPC server running on :50051")
	if err := grpcServer.Serve(lis); err != nil {
		log.Fatal(err)
	}
}
