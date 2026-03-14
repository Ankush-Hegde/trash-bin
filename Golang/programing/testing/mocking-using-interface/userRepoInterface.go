package mocking_interface

// define interface

type UserRepository interface {
	FindByID(id int) (string, error)
}
