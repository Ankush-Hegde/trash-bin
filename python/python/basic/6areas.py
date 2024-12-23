while(1):
	print('\n---------- find area of -------------')
	print('\n1.square\n2.rectangle\n3.circle\n4.EXIT')
	print('\n-------------------------------------')
	print('ENTER UR VALUE\n')
	choice=int(input())
	if choice==1:
		print('\n')
		sides = int(input('enter length of sides : '))
		print('area:'+str(sides*sides))
	elif choice==2:
		print('\n')
		l = int(input('enter legth : '))
		b = int(input('\nenter bredth : '))
		print('area:'+str(l*b))
	elif choice==3:
		print('\n')
		r = int(input('enter radius : '))
		print('area:'+str(r*3.14*r))
	elif choice==4:
		print('\nrun my code again')
		break;
	else:print('invalid choice')
