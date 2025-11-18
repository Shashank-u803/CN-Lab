import socket
import os 
HOST = '127.0.0.1'
PORT = 5001

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((HOST,PORT))

print("Server is running...waiting for filename")
try:
    while True:
        data,addr = s.recvfrom(1024)
        print(addr)
        fname = data.decode()
        if not fname:
            break
        print("Requested file:",fname)
        if os.path.isfile(fname):
            with open(fname,"r") as f:
                content = f.read()
            s.sendto(content.encode(),addr)
        else:
            s.sendto("File not found".encode(),addr)
except KeyboardInterrupt:
    print("Shutting down server...")
    s.close()
