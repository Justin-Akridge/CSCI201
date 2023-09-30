/*
 * Justin Akridge
 * 09/30/2023
 * Server
 * This program starts a server that allows multiple clients to connect to it
 * for communication
 */

#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <limits>

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

int main() {
  int server_socket, new_socket;
  struct sockaddr_in server_addr, new_addr;
  char buffer[BUFFER_SIZE];
  socklen_t addr_size;

  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    std::cerr << "Error in connection.\n";
    exit(EXIT_FAILURE);
  }
  std::cout << "Server socket created.\n";

  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  int bind_status = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (bind_status < 0) {
    std::cerr << "ERROR: Binding failed.\n";
    exit(EXIT_FAILURE);
  }
  std::cout << "Binding success.\n";

  int listen_status = listen(server_socket, 10);
  if (listen_status == 0) {
    std::cout << "Listening...\n";
  } else {
    std::cerr << "ERROR: Listen failed.\n";
    exit(EXIT_FAILURE);
  }

  addr_size = sizeof(new_addr);
  new_socket = accept(server_socket, (struct sockaddr*)&new_addr, &addr_size);

  if (new_socket < 0) {
    std::cerr << "Server accept failed.\n";
    exit(EXIT_FAILURE);
  }

  std::unordered_map<std::string, std::string> states = {
    { "AL", "Alabama"}, {"AZ", "Arizona"}, {"AR", "Arkansas"}, {"CA", "California"},
    {"CO", "Colorado"}, {"CT", "Connecticut"}, {"DE", "Delaware"}, {"FL", "Florida"},
    {"GA", "Georgia"}, {"HI", "Hawaii"}, {"ID", "Idaho"}, {"IL", "Illinois"}, {"IN", "Indiana"},
    {"IA", "Iowa"}, {"KS", "Kansas"}, {"KY", "Kentucky"}, {"LA", "Louisiana"}, {"ME", "Maine"},
    {"MD", "Maryland"}, {"MA", "Massachusetts"}, {"MI", "Michigan"}, {"MN", "Minnesota"},
    {"MS", "Mississippi"}, {"MO", "Missouri"}, {"MT", "Montana"}, {"NE", "Nebraska"},
    {"NV", "Nevada"}, {"NH", "New Hampshire"}, {"NJ", "New Jersey"}, {"NM", "New Mexico"}, 
    {"NY", "New York"}, {"NC", "North Carolina"}, {"ND", "North Dakota"}, {"OH", "Ohio"}, 
    {"OK", "Oklahoma"}, {"OR", "Oregon"}, {"PA", "Pennsylvania"}, {"RI", "Rhode Island"},
    {"SC", "South Carolina"}, {"SD", "South Dakota"}, {"TN", "Tennessee"}, {"TX", "Texas"}, 
    {"UT", "Utah"}, {"VT", "Vermont"}, {"Va", "Virginia"}, {"WA", "Washington"}, 
    {"WV", "West Virginia"}, {"WI", "Wisconsin"}, {"WY", "Wyoming"}
  };
  do {
    recv(new_socket, buffer, BUFFER_SIZE, 0);
    std::cout << "(Client) State abbreviation recieved: " << buffer << "\n";
    std::string message(buffer);
    std::cout << typeid(message).name() << std::endl;
    for (auto &i: message) {
      i = std::toupper(i);
    }
    bool is_valid_state = false;
    for (auto i : states) {
      if (i.first == message) {
        is_valid_state = true;
        send(new_socket, states[message].c_str(), states[message].length(), 0);
        std::cout << "Message sent to client: " << message << std::endl;
      }
    }
    if (!is_valid_state) {
      std::string error = "The state abbreviation entered is not a state abbreviation.";
      send(new_socket, error.c_str(), error.size(), 0);
    }
  } while (*buffer != '#');

  close(new_socket);
  close(server_socket);
}
