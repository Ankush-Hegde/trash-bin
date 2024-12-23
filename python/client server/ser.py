#!/usr/bin/env python3

import socket

h='127.0.0.1'
p=65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.bind((h,p))
	s.listen()
	conn, addr = s.accept()
	with conn:
		print('connected by', addr)
		while True:
			data =conn.recv(1024)
			if not data :
				break
			conn.sendall(data)
