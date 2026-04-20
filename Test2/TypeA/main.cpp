#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int port = 8080;

    // 1. Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        return 1;
    }

    // 2. Set up address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(port);

    // 3. Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // 4. Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return 1;
    }

    std::cout << "Server running on port " << port << "..." << std::endl;

    while (true) {
        // 5. Accept an incoming connection
        int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // 6. Send a basic HTTP Response
        std::string response = 
            "HTTP/1.1 200 OK\n"
            "Content-Type: text/plain\n"
            "Content-Length: 12\n\n"
            "Hello World!";
        
        send(new_socket, response.c_str(), response.length(), 0);
        
        // 7. Close the connection
        close(new_socket);
    }

    return 0;
}