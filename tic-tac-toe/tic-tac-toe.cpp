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
  Board() {
    board = {{'#', '#', '#'}, 
             {'#', '#', '#'},
             {'#', '#', '#'}};
  }

  void fill_board(int height, int width) {
    for (size_t i = 0; i < height; i++) {
      for (size_t j = 0; j < width; j++) {
        board[i][j] = '#';
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
    std::cout << '\n';
  }

  std::vector<std::vector<char> > board;

#if 0
  // New feature: implement custom board size

  std::array<int, 2> validate_board_size(std::string board_size) {
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

  bool validate_size(const std::array<int, 2> &arr) {
    for (const auto &digit : arr) {
      if (digit < 3 || digit > 10)
        return false;
    }
    return true;
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
#endif
};

struct Player {
  char marker = 'x'; 
  int wins = 0;
  int losses = 0;
};

struct Computer {
  char marker = 'o';
  int wins = 0;
  int losses = 0;
};

static void computer_play(char marker, std::vector<std::vector<char> > &board) {
  bool done = false;
  while (!done) {
    int x = rand() % board.size();
    int y = rand() % board[0].size();
    if (board[x][y] == '#') {
      board[x][y] = marker;
      done = true;
    } 
  }
}

bool check_for_winner(char marker, std::vector<std::vector<char> > &board) {
       // Check for horizontal win
  if ((board[0][0] == marker && board[0][1] && board[0][2] == marker) ||
      (board[1][0] == marker && board[1][1] && board[1][2] == marker) ||
      (board[2][0] == marker && board[2][1] && board[2][2] == marker) ||

      // Check for vertical win
      (board[0][0] == marker && board[1][0] && board[2][0] == marker) ||
      (board[0][1] == marker && board[1][1] && board[2][1] == marker) ||
      (board[0][2] == marker && board[1][2] && board[2][2] == marker) ||
      
      // Check for diagonal win
      (board[0][0] == marker && board[1][1] && board[2][2] == marker) ||
      (board[0][2] == marker && board[1][1] && board[2][0] == marker)) {
    return true;
  } else {
    return false;
  }
}
bool check_for_valid_space(char position) {
  return position == '#';
};


static void players_play(char marker, std::vector<std::vector<char> > &board) {
  bool done = false;
  while (!done) {
    char row = '\0';
    bool valid_row = false;
    while (!valid_row) {
      std::cout << "Pick a row 0 - 2 that contains a #: ";
      std::cin >> row;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (row == '0' || row == '1' || row == '2') {
        valid_row = true;
      } else {
        std::cerr << "Error: " << row << " is not a valid row.\n\n";
      }
    }

    char col = '\0';
    bool valid_col = false;
    while (!valid_col) {
      std::cout << "Pick a column 0 - 2 that contains a #: ";
      std::cin >> col;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (col == '0' || col == '1' || col == '2') {
        valid_col = true;
      } else {
        std::cerr << "Error: " << col << " is not a valid column.\n\n";
      }
    }
    if (board[row][col] == '#') {
      board[row][col] = marker;
      done = true;
    } else {
      std::cerr << "Position has already been taken!\n";
    }
  }
  std::cout << '\n';
}

int main() {
  std::cout << "------TIC-TAC-TOE-------\n\n";
  Board tic_tac_toe;
  Player player1;
  Computer computer1;
  
  while (true){ 
    tic_tac_toe.display_board();
    players_play(player1.marker, tic_tac_toe.board);
    if (check_for_winner(player1.marker, tic_tac_toe.board)) {
      tic_tac_toe.display_board();
      std::cout << "Player wins" << std::endl;
      break;
    }
    //computer_play(computer1.marker, tic_tac_toe.board);
    //if (check_for_winner(computer1.marker, tic_tac_toe.board)) {
    //  std::cout << "Computer wins" << std::endl;
    //  break;
    //}
  }
}
