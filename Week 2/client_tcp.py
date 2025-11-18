import socket

HOST = '127.0.0.1'
PORT = 5000

s = socket.socket()
s.connect((HOST,PORT))

fname = input("Enter File name:")
s.send(fname.encode())

data = s.recv(4096).decode()
print("====File Contents====")
print(data)

s.close()
