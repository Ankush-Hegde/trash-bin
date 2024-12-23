def a():
	print('a')
	b()
	print('a returns')
def b():
	print('b')
	c()
	print('b returns')
def c():
	print('c')
	d()
	print('c returns')
def d():
	print('d')
	print('d returns')

a()
