// client.cpp
#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

const int PORT = 8080;
const char* SERVER_ADDR = "127.0.0.1";
const char* MESSAGE = "Hello from client!";
const int BUFFER_SIZE = 1024;

int main() {
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    if (WSAStartup(ver, &wsData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return -1;
    }

    SOCKET clientSocket;
    sockaddr_in serverAddr;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Connection Failed" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return -1;
    }

    send(clientSocket, MESSAGE, strlen(MESSAGE), 0);
    std::cout << "Message sent to server: " << MESSAGE << std::endl;

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
