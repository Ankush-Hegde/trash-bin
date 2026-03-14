advance test uses

✔ Test Coverage
=> go test -cover

Detailed:

=> go test -coverprofile=coverage.out
=> go tool cover -html=coverage.out

✔ Test Setup / Teardown
func TestMain(m *testing.M) {
	// setup
	code := m.Run()
	// teardown
	os.Exit(code)
}

✔ Parallel Tests
t.Parallel()

✔ Tests race
go test -race