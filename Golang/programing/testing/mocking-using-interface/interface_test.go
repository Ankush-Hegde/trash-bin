package mocking_interface

import "testing"

func TestGetUserName(t *testing.T) {
	mockRepo := &MockUserRepo{}
	service := NewUserService(mockRepo)

	name, _ := service.GetUserName(1)

	if name != "John" {
		t.Errorf("expected John, got %s", name)
	}
}
