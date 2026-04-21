# e.g
import socket
import json
c = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
c.connect("/tmp/worker.sock")
while True:
    d = c.recv(65535)
    if not d: break
    try:
        m = json.loads(d.decode().split('\r\n\r\n')[-1])
        if m.get('t') == 'MESSAGE_CREATE':
            print(f"New Message: {m['d']['content']}")
    except: continue
