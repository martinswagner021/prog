# type: ignore
from socket import *
from time import sleep

MAX_BUFF_SIZE = 1024

ip_addr = ''
server_port = 12000

clientSocket = socket(AF_INET, SOCK_STREAM)
while 1:
    clientSocket.connect((ip_addr, server_port))
    answer = input('Answer: ')
    clientSocket.send(bytes(answer, 'UTF-8'))
    response = clientSocket.recv(MAX_BUFF_SIZE)
    print(response)
    clientSocket.close()