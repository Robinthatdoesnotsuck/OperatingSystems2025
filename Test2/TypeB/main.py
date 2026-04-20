import socket

def run_server():
    # AF_INET = IPv4, SOCK_STREAM = TCP
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(('0.0.0.0', 8080))
        s.listen()
        print("Python server on 8080...")
        
        while True:
            conn, addr = s.accept()
            with conn:
                request = conn.recv(1024) # We don't even need to parse it for this demo
                response = (
                    "HTTP/1.1 200 OK\r\n"
                    "Content-Type: text/plain\r\n"
                    "Content-Length: 13\r\n\r\n"
                    "Hello Python!"
                )
                conn.sendall(response.encode())

run_server()