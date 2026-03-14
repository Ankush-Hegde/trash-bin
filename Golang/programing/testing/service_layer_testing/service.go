package user

type UserService struct{}

func (s *UserService) GetUserName(id int) string {
	if id == 1 {
		return "John"
	}
	return ""
}
