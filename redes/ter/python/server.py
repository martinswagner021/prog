# type: ignore
from socket import *
from threading import Thread

MAX_BUFF_SIZE = 1024


Thread.start()
def handle_client(client_socket):
    while True:
        message = client_socket.recv(MAX_BUFF_SIZE)
        if not message:
            break
        print(f"Received: {message.decode('UTF-8')}")
        client_socket.send(message)
    client_socket.close()

# Create a TCP socket

def start_server():
    server_socket = socket(AF_INET, SOCK_STREAM)
    server_socket.bind(('', 8888))
    server_socket.listen(5)
    print("Server listening on port 8888...")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Accepted connection from {addr}")
        client_handler = Thread(target=handle_client, args=(client_socket,))
        client_handler.start()


server_port = 8888
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', server_port))
serverSocket.listen()

chat_hosts = ""

print(f'Listening on {server_port}...')
try:
    while 1:
        conn, addr = serverSocket.accept()
        sentence = conn.recv(MAX_BUFF_SIZE)
        sentence = sentence.decode('UTF-8')
        if not chat_hosts == "":
            chat_hosts.append(",")
        chat_hosts.append(sentence)
        conn.send(bytes(chat_hosts.encode('UTF-8')))
        conn.close()

except:
    serverSocket.close()
    print("\nServer shut down")