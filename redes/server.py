# type: ignore
from socket import *

MAX_BUFF_SIZE = 1024

server_port = 12000
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', server_port))
serverSocket.listen(1)

print(f'Listening on {server_port}')
while 1:
    conn, addr = serverSocket.accept()
    sentence = conn.recv(MAX_BUFF_SIZE)
    print("Received:", sentence)
    answer = input('Answer: ')
    conn.send(bytes(answer, 'UTF-8'))
    conn.close()
