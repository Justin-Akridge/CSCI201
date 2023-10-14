#include <iostream>
#include <array>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

class Board {
public:
  Board() {}
  Board(int x, int y) {
    resize(x, y);
  }

  void fill_board() {
    int count = 0;
    for (size_t i = 0; i < board.size(); i++) {
      for (size_t j = 0; j < board[i].size(); j++) {
        if (count < 10) {
          board[i][j] = (count < 10) ? count + '0' : (count - 10) + 'A';
          count++;
        }
      }
    }
  }

  void display_board() {
    for (const auto &row : board) {
      for (const auto &col : row) {
        std::cout << col << " "; 
      }
      std::cout << '\n';
    }
  }

  std::array<int, 2> parser(std::string board_size) {
    std::array<int, 2> arr {-1,-1};
    std::string builder = "";
    for (size_t i = 0; i < board_size.size(); i++) {
      if (board_size[i] == 'x' || board_size[i] == 'X') {
        arr[0] = std::stoi(builder);
        builder = "";
      } else if (std::isdigit(board_size[i]) && i == board_size.size() - 1) {
        builder += board_size[i];
        arr[1] = std::stoi(builder);
      } else if (std::isdigit(board_size[i])) {
        builder += board_size[i];
      } else if (std::isspace(board_size[i])) {
        continue;
      } else {
        std::cout << "Value entered is not in the correct format! "
                  << "Please enter board size in format (4x4)\n";
      }
    }
    return arr;
  }

  bool validate_size(std::array<int, 2> &arr) {
    for (const auto &digit : arr) {
      if (digit < 3) {
        std::cerr << "Board size must be greater then or equal to 3x3\n";
        return false;
      }
    }
    return true;
  }

  void resize(int x, int y) {
    board.resize(x, std::vector<char>(y, '0'));
    fill_board();
  }

  void set_custom_dimension() {
    bool done = false;
    while (!done) {
      std::cout << "Enter the size of the playing board (ex: 4x4): ";
      std::string size;
      std::getline(std::cin, size);
      std::array<int, 2> arr = parser(size);
      if (validate_size(arr)) {
        resize(arr[0], arr[1]);
        done = true;
      } else {
        std::cerr << "Invalid input. Please enter in the same format as the example.\n";
      }
    }
  }

private:
  std::vector<std::vector<char>> board;
};

struct Player {
  char marker; 
  int wins = 0;
  int losses = 0;
};

void bot(std::vector<std::vector<char>> &board) {
  int x = rand() % board.size();
  int y = rand() % board[0].size();
  if (board[x][y] == 0) {
    board[x][y] = 1;
  } else {
    bot(board);
  }
}

int main() {
  std::cout << "------TIC-TAC-TOE-------\n";
  std::cout << "Would like you like to play tic-tac-toe with default settings? [y/n] ";
  char response = '\0';
  std::cin >> response;
  std::cin.ignore(256, '\n');
  response = std::tolower(response);

  Board board;
  if (response == 'y') {
    board.resize(3,3);
  } else if (response == 'n') {
    board.set_custom_dimension(); 
  }
  board.display_board();
  
}
