import tkinter as tk
from tkinter import *


while(1):
	name = input('enter username : ')
	passd = input('enter password : ')
	if name!='skull' or  passd!='skull@123':
			print('\a--------------\n ACCESS DENIED\n-----------\n')
			continue

	break
print('\n--------------------ACCESS GRANTED---------------\n')
