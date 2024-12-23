import socket

serverPort = 12000
serverSocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)
print ("The server is ready to receive")
while 1:
    connectionSocket, addr = serverSocket.accept()
#    byte_sentence = connectionSocket.recv(1024)
#    utf_sentence = byte_sentence.decode("utf-8")
#    modified_utf_sentence = utf_sentence.upper()
#    modified_byte_sentence = bytes(modified_utf_sentence, "utf-8")

#connectionSocket.send(modified_byte_sentence)
    print('connected' ,addr)
    data=connectionSocket.recv(1024)
    print('\n',data)
    
    
#connectionSocket.close()
