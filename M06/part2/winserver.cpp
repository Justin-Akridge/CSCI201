// server.cpp
#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

int main() {
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    if (WSAStartup(ver, &wsData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return -1;
    }

    SOCKET serverSocket;
    sockaddr_in serverAddr;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    SOCKET newSocket;
    sockaddr_in newAddr;
    int addrSize = sizeof(newAddr);

    newSocket = accept(serverSocket, (struct sockaddr*)&newAddr, &addrSize);
    if (newSocket == INVALID_SOCKET) {
        std::cerr << "Accept failed" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int recvSize = recv(newSocket, buffer, BUFFER_SIZE, 0);
    std::cout << "Received message from client: " << buffer << std::endl;

    closesocket(newSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
