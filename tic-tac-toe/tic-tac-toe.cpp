#include <iostream>
#include <array>
#include <limits>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

class Board {
public:
  Board() {}
  Board(int x, int y) {
    resize_this(x, y);
  }

  void fill_board() {
    std::string count = "0";
    for (size_t i = 0; i < board.size(); i++) {
      for (size_t j = 0; j < board[i].size(); j++) {
        board[i][j] = count;
        int tmp = std::stoi(count);
        count = std::to_string(++tmp);
      }
    }
  }

  void display_board() {
    for (const auto &row : board) {
      for (const auto &col : row) {
        std::cout << std::setw(2) << col << " "; 
      }
      std::cout << '\n';
    }
  }

  std::array<int, 2> parser(std::string board_size) {
    std::array<int, 2> arr {-1, -1};
    std::string builder = "";
    bool is_not_valid_board_size = false;
    bool has_one_x = false;
    bool has_first_value = false;
    for (size_t i = 0; i < board_size.size(); i++) {
      if (board_size[i] == 'x' || (board_size[i] == 'X' && has_first_value && !has_one_x)) {
        has_one_x = true;
        arr[0] = std::stoi(builder);
        builder = "";
      } else if (std::isdigit(board_size[i]) && i == board_size.size() - 1 && has_first_value && has_one_x) {
        builder += board_size[i];
        arr[1] = std::stoi(builder);
      } else if (std::isdigit(board_size[i])) {
        builder += board_size[i];
      } else if (std::isspace(board_size[i])) {
        continue;
      } else {
        is_not_valid_board_size = true;
        break;
      }
    }
    if (is_not_valid_board_size) {
      std::cout << "Value entered is not in the correct format! "
                << "Please enter board size in format (4x4)\n";
    }
    return arr;
  }

  bool validate_size(std::array<int, 2> &arr) {
    for (const auto &digit : arr) {
      if (digit < 3 || digit > 10)
        return false;
    }
    return true;
  }

  void resize_this(int x, int y) {
    board.resize(x, std::vector<std::string>(y));
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
        resize_this(arr[0] , arr[1]);
        done = true;
      } else if (arr[0] < 3 && arr[1] < 3) {
        std::cerr << "Invalid board size. Board must be less a 3x3\n"; 
      } else if (arr[0] > 10 && arr[1] > 10) {
        std::cerr << "Invalid board size. Board must be less a 10x10\n"; 
      } else if (arr[0] < 3 && arr[1] > 10) {
        std::cerr << "Invalid board size. Column size must be greater then 3 columns. "
                  << "Row size must be less then 10.\n"; 
      } else if (arr[0] > 10 && arr[1] < 3) {
        std::cerr << "Invalid board size. Column size must be less then 10 columns. "
                  << "Row size must be greater then 3.\n"; 
      } else {
        std::cerr << "Invalid input. Please enter in the same format as the example.\n\n";
      }
    }
  }

private:
  std::vector<std::vector<std::string>> board;
};

struct Player {
  char marker; 
  int wins = 0;
  int losses = 0;
};

void bot(std::vector<std::vector<std::string>> &board) {
  int x = rand() % board.size();
  int y = rand() % board[0].size();
  if (board[x][y] == "0") {
    board[x][y] = "1";
  } else {
    bot(board);
  }
}

int main() {
  std::cout << "------TIC-TAC-TOE-------\n";
  bool done = false;
  while (!done) {
    std::cout << "Would like you like to play tic-tac-toe with default settings? [y/n] ";
    char response = '\0';
    std::cin >> response;
    std::cin.ignore(256, '\n');
    response = std::tolower(response);

    Board board;
    if (response == 'y') {
      board.resize_this(3, 3);
    } else if (response == 'n') {
      board.set_custom_dimension(); 
    }
    board.display_board();
  }
}
