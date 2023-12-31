/*
 * Justin Akridge
 * 09/30/2023
 * Client
 * This program connects the client to a server for communication
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <limits>

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

int main() {
  int client_socket;
  struct sockaddr_in server_addr;
  char buffer[BUFFER_SIZE];
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
      std::cerr << "Error in connection.\n";
      exit(EXIT_FAILURE);
  }
  std::cout << "Client socket created.\n";

  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  int connect_status = connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (connect_status == 0) {
      std::cout << "Connected to server.\n";
  } else {
      std::cerr << "Connection to server failed.\n";
      exit(EXIT_FAILURE);
  }

  while (true) {
    std::string state_abbrev = "";
    std::cout << "Enter a state abbreviation or # to quit: ";
    std::cin >> state_abbrev;
    if (state_abbrev == "#") {
      std::cout << "Goodbye!" << std::endl;
      exit(EXIT_SUCCESS);
    } else {
      send(client_socket, state_abbrev.c_str(), state_abbrev.length(), 0);
      std::cout << "The state abbreviation sent to server: " << state_abbrev << "\n";
      recv(client_socket, buffer, BUFFER_SIZE, 0);
      std::string tmp(buffer);
      std::string recieved = "";
      for (int i = 0; i < tmp.size(); i++) {
        if (std::isalpha(tmp[i])) {
          recieved += tmp[i];
        }
      }
      if (recieved == "ERROR") { 
        std::cout << "The input is not a valid state abbreviation." << std::endl;
      } else {
        std::cout << "(Server) The state is abbreviation stands for: " << recieved << std::endl;
      }
    }
  }
  close(client_socket);
}
