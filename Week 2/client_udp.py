import socket

HOST = '127.0.0.1'
PORT = 5001

fname = input("Enter file name:")

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.sendto(fname.encode(),(HOST,PORT))

data, addr = s.recvfrom(4096)

print("===FILE CONTENTS===")
print(data.decode())

s.close()
