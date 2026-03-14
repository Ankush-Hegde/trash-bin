package beanchmarkapi

type UserRepository interface {
	FindByID(id int) (string, error)
}

type UserService struct {
	repo UserRepository
}

func NewUserService(repo UserRepository) *UserService {
	return &UserService{repo: repo}
}

func (s *UserService) GetUserName(id int) (string, error) {
	return s.repo.FindByID(id)
}
