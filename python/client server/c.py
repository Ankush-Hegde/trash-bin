#!/usr/bin/env python3

import socket 
h='127.0.0.1'
#p=65432
p=12000

#with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
#	s.connect((h,p))
#	i=input('enter\n')
#	s.sendall(bytes(i))
#	data= s.recv(1024)
#print ('recevied',repr (data))




with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.connect((h,p))
	while 1:
	 i=input('enter\n')
	 modified_byte_sentence = bytes(i, "utf-8")
	 s.sendall(modified_byte_sentence)
	
	#s.sendall(bytes(i))
	data= s.recv(1024)
print ('recevied',repr (data))
