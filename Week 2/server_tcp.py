import socket
import os

#define host ip and port
HOST = '127.0.0.1'
PORT = 5000

#create server socket and bind it
s = socket.socket()
s.bind((HOST,PORT))
s.listen(1)

print("Server is running, waiting for connection....")

connection_socket, address = s.accept()
print("Connected with:",address)
try:
    while True:
        fname = connection_socket.recv(1024).decode()
        if not fname:
            break
        print(f"Client requested:{fname}")

        if os.path.isfile(fname):
            with open(fname,"r") as f:
                data = f.read()
            connection_socket.send(data.encode())
        else:
            connection_socket.send("File not found".encode())
except KeyboardInterrupt:
    print("Shutting down server....")
    connection_socket.close()
    s.close()
