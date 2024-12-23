class  p:
	x=1
	v=8
	def __init__(self,x,v) :
		x+=v
		return x
class o(p):
	 j=3
#	def __init__(self,j):
#		self.j=2

print(o.j)
print(o.x)
print(p.v)
