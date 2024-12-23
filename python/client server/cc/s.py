import socket

serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('created')
serv.bind(('127.0.0.1',1111))
serv.listen(5)

while True:
    conn, addr = serv.accept()
    from_client = ''

    while True:
        data = conn.recv(4096)
        if not data: break
        from_client += data
        print ('from_client')
        conn.send("I am SERVER\n")
        
    conn.close()
    print ('client disconnected')
