import random

list= ['a','b','c','d','e','f','g','h']

def shuffle(x):
	print(x)
	random.shuffle(x)
	return(print(x))
def choice(x):
	print(x)
	return(print(random.choice(x)))
def display(x):
	return(print(x))

while(1):
	print("\n-------------------------------------------------------------\nenter ur choice\n1.shuffel\n2.choice\n3.display\n-------------------------------------------------------------\n")
	num=int(input())

	if(num==1):
		print('\n\n')
		print(shuffle(list))
	elif(num==2):
		print('\n\n')
		print(choice(list))
	elif(num==3):
		print('\n\n')
		print(display(list))
	else:
		print("invalid input")
