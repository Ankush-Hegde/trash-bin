package user

import "testing"

// testing service.go which is a service,
// in real case you can use interface to mock it instead
func TestGetUserName(t *testing.T) {
	service := &UserService{}

	tests := []struct {
		id       int
		expected string
	}{
		{1, "John"},
		{2, ""},
	}

	for _, tt := range tests {
		result := service.GetUserName(tt.id)
		if result != tt.expected {
			t.Errorf("expected %s, got %s", tt.expected, result)
			t.Fail()
		}
	}
}
