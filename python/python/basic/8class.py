class point:
	x=0
	y=0
class rect:
	hight=0
	width=0
	corner=point()

box=rect()
box.hight='done'
box.width=3
box.corner.x=4
box.corner.y=5

print('\nhight : '+str(box.hight)+'\nwidth : '+str(box.width)+'\ncorner.x : '+str(box.corner.x)+'\ncorner.y : '+str(box.corner.y))
