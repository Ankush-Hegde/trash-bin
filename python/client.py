from socket import *
serverName = 'localhost'
serverPort = 12000

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
sentence = input(r'Input lowercase sentence:')


'''utf=sentence.encode("utf-8")

bytes_sentence=bytes(utf)


clientSocket.send(bytes_sentence,'utf-8')
'''

clientSocket.send(sentence)
modifiedSentence = clientSocket.recv(1024)
print ('From Server:'+ modifiedSentence)
clientSocket.close()
