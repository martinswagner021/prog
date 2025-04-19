# type: ignore
from socket import *

MAX_BUFF_SIZE = 1024

name = 'wagner'
my_ip_addr = ''
my_port = 8889

server_ip_addr = ''
server_port = 8888

clientSocket = socket(AF_INET, SOCK_STREAM)

clientSocket.connect((server_ip_addr, server_port))

messageSocket = socket(AF_INET, SOCK_STREAM)
messageSocket.bind(('', my_port))
messageSocket.listen()

apresentacao = f'{name}:{my_ip_addr}:{my_port}'.encode('UTF-8')

clientSocket.send(apresentacao)
print(clientSocket.recv(MAX_BUFF_SIZE))

chat_hosts = []

print(f'Listening on {my_port}...')
try:
    while 1:
        conn, addr = messageSocket.accept()
        sentence = conn.recv(MAX_BUFF_SIZE)
        sentence = sentence.decode('UTF-8')
        print("Received:", sentence)
        conn.close()
except:
    messageSocket.close()
    clientSocket.close()
    print("\nServer shut down")
