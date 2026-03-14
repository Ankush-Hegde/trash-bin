package beanchmarkapi

import "testing"

// to run it with real api function
func BenchmarkGetUserName(b *testing.B) {
	mockRepo := &MockUserRepo{}
	service := NewUserService(mockRepo)

	for i := 0; i < b.N; i++ {
		service.GetUserName(1)
	}
}
