package beanchmarkapi

type MockUserRepo struct{}

func (m *MockUserRepo) FindByID(id int) (string, error) {
	if id == 1 {
		return "John", nil
	}
	return "", nil
}
