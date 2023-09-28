#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
  const BUFFER_SIZE = 1024;
  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};
  
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perrer("Socket failed to create");
    exit(EXIT_FAILURE); 
  }

  if (setsockopt(server_fd, SOL_SOCKET, SOREUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("Setsockopt failed");
    exist(EXIT_FAILURE);
  } 

  address.sin.family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port  = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  int valread = read(new_socket, buffer, BUFFER_SIZE);
  printf("Received message from client: %s\n", buffer);
}
