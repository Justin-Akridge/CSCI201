#include <iostream>
#include <array>
#include <limits>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <random>
#include <ctime>

class Board {
public:
  Board() {
    std::cout << "Would you like to play with default settings? [y/n]: ";
    char res;
    std::cin >> res;
    std::cout << '\n';
    if (res == 'y') {
      constexpr int height_of_board = 3;
      constexpr int width_of_board = 3;
      board.resize(height_of_board, std::vector<char>(width_of_board, '#'));
    } else if (res == 'n') {
      set_custom_dimension();
    } else {
      std::cout << "Error: invalid input. Enter either y for yes or n for no\n";
    }
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

  void set_custom_dimension() {
    bool done = false;
    while (!done) {
      std::cout << "Enter the size of the playing board (ex: Enter 10 for 10x10 board): ";
      int size_of_board;
      std::cin >> size_of_board;
      std::cout << '\n';
      if (size_of_board >= 3 && size_of_board <= 10) {
        board.resize(size_of_board, std::vector<char>(size_of_board, '#'));
        done = true;
      } else {
        std::cerr << "Invalid input. Size of board must be greater than 3 and less than 10.\n"
                     "Please enter in the same format as the example.\n\n";
      }
    }
  }

  bool is_a_tie() {
    for (const auto &row : board) {
      for (const auto &col : row) {
        if (col == '#') {
          return false;
        }
      }
    }
    return true;
  }

  bool check_for_winner(char marker) {
         // Check for horizontal win
    if ((board[0][0] == marker && board[0][1] == marker && board[0][2] == marker) ||
        (board[1][0] == marker && board[1][1] == marker && board[1][2] == marker) ||
        (board[2][0] == marker && board[2][1] == marker && board[2][2] == marker) ||

        // Check for vertical win
        (board[0][0] == marker && board[1][0] == marker && board[2][0] == marker) ||
        (board[0][1] == marker && board[1][1] == marker && board[2][1] == marker) ||
        (board[0][2] == marker && board[1][2] == marker && board[2][2] == marker) ||
        
        // Check for diagonal win
        (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) ||
        (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker)) {
      return true;
    } else {
      return false;
    }
  }

  std::vector<std::vector<char> > board;
                                       
                                       
};

class Player {
public:
  Player() {
    set_marker();
  }

  void set_marker() {
    bool done = false;
    while (!done) {
      std::cout << "Set player marker:\n1 for X or 2 for O: ";
      char res = '\0';
      std::cin >> res;
      if (res == '1') {
        done = true;
      } else if (res == '2') {
        marker = 'O';     
        done = true;
      } else {
        std::cerr << "Error: invalid input. Input must be either 1 or 2\n";
      }
    }
  }

  void players_play(char marker, std::vector<std::vector<char> > &board) {
    bool done = false;
    while (!done) {
      char row_input = '\0';
      int row = 0;
      bool valid_row = false;
      while (!valid_row) {
        std::cout << "Pick a row 1 - 3 that contains a #: ";
        std::cin >> row_input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (row_input == '1' || row_input == '2' || row_input == '3') {
          switch (row_input) { 
            case '1':
              row = 0;
              break;
            case '2':
              row = 1;
              break;
            case '3':
              row = 2;
              break;
          }
          valid_row = true;
        } else {
          std::cerr << "Error: " << row << " is not a valid row.\n\n";
        }
      }

      char col_input = 0;
      int col = 0;
      bool valid_col = false;
      while (!valid_col) {
        std::cout << "Pick a column 1 - 3 that contains a #: ";
        std::cin >> col_input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (col_input == '1' || col_input == '2' || col_input == '3') {
          switch (col_input) {
            case '1':
              col = 0;
              break;
            case '2':
              col = 1;
              break;
            case '3':
              col = 2;
              break;
          }
          valid_col = true;
        } else {
          std::cerr << "Error: " << col << " is not a valid column.\n\n";
        }
      }

      if (board[row][col] == '#') {
        board[row][col] = marker;
        done = true;
      } else {
        std::cerr << "\nPosition has already been taken!\n\n";
      }
    }
    std::cout << '\n';
  }

  void print_score() {
    std::cout << "\n--------Player's Score---------\n";
    std::cout << "Wins : " << wins << '\n';
    std::cout << "Losses : " << losses << "\n\n";
  } 

  char marker = 'X'; 
  int wins = 0;
  int losses = 0;
};

class Computer {
  public:
  void computer_play(char op_marker, char cp_marker, Board &tic_tac_toe) {
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        if (tic_tac_toe.board[i][j] == '#') {
          tic_tac_toe.board[i][j] = cp_marker;
          if (tic_tac_toe.check_for_winner(cp_marker)) {
            return;
          }
          tic_tac_toe.board[i][j] = '#';

          tic_tac_toe.board[i][j] = op_marker;
          if (tic_tac_toe.check_for_winner(op_marker)) {
            tic_tac_toe.board[i][j] = cp_marker;
            return;
          }
          tic_tac_toe.board[i][j] = '#';
        }
      }
    }
    int x = 0;
    int y = 0;
    std::mt19937 generator(static_cast<unsigned>(std::time(0)));
    std::uniform_int_distribution<int> distribution(0, tic_tac_toe.board.size() - 1);
    do {
      x = distribution(generator);
      y = distribution(generator);
    } while (tic_tac_toe.board[x][y] != '#');

    tic_tac_toe.board[x][y] = cp_marker;
  }
  
  void print_score() {
    std::cout << "\n--------Computer's Score---------\n";
    std::cout << "Wins : " << wins << '\n';
    std::cout << "Losses : " << losses << "\n\n";
  } 

  char marker = 'O';
  int wins = 0;
  int losses = 0;
};

template <typename T>
T random_number_generator(T first, T last) {
  std::mt19937 generator(static_cast<unsigned>(std::time(0)));
  std::uniform_int_distribution<int> distribution(first, last);
  return distribution(generator);
}

int main() {
  std::cout << "------TIC-TAC-TOE-------\n\n";
  Board tic_tac_toe;
  Player player;
  Computer computer;

  // Upon creation of player object, if player decides to pick there own marker,
  // we will assign the oposite marker to the computer. See Player constructor.
  if (player.marker == 'O') {
    computer.marker = 'X';
  }  

  std::cout << "Lets flip a coin to see who goes first\n";
  // 0 is the computer and 1 is the player in the generator
  // The algorithm will pick the player to go first for the first game. 
  // Thereafter, the winner will be the one to go first
  int player_to_go_first = random_number_generator(0,1);

  // Player goes first. 
  // TODO [_] find a clever way to avoid repeating this block. The if/else block is
  // the same but flips the functions to whichever player goes first.
  bool done = false;
  while (!done) {
    if (player_to_go_first) {
      std::cout << "You go first!\n";
      while (true) {
        tic_tac_toe.display_board();
        player.players_play(player.marker, tic_tac_toe.board);
        if (tic_tac_toe.check_for_winner(player.marker)) {
          player_to_go_first = 1;
          player.wins++;
          computer.losses++;
          tic_tac_toe.display_board();
          std::cout << "Player wins" << std::endl;
          break;
        }
        if (tic_tac_toe.is_a_tie()) {
          tic_tac_toe.display_board();
          std::cout << "\nTie!\n\n";
          break;
        }
        computer.computer_play(player.marker, computer.marker, tic_tac_toe);
        if (tic_tac_toe.check_for_winner(computer.marker)) {
          player_to_go_first = 0;
          computer.wins++;
          player.losses++;
          tic_tac_toe.display_board();
          std::cout << "Computer wins" << std::endl;
          break;
        }
      }
    } else {
      // TODO [_] find a clever way to avoid repeating this block. The if/else block is
      // the same but flips the functions to whichever player goes first.
      std::cout << "Computer goes first!\n";
      while (true) { 
        computer.computer_play(player.marker, computer.marker, tic_tac_toe);
        if (tic_tac_toe.check_for_winner(computer.marker)) {
          player_to_go_first = 0;
          computer.wins++;
          player.losses++;
          tic_tac_toe.display_board();
          std::cout << "Computer wins" << std::endl;
          break;
        }
        if (tic_tac_toe.is_a_tie()) {
          tic_tac_toe.display_board();
          std::cout << "\nTie!\n\n";
          break;
        }
        tic_tac_toe.display_board();
        player.players_play(player.marker, tic_tac_toe.board);
        if (tic_tac_toe.check_for_winner(player.marker)) {
          player_to_go_first = 1;
          player.wins++;
          computer.losses++;
          tic_tac_toe.display_board();
          std::cout << "Player wins" << std::endl;
          break;
        }
      }
    }
    std::cout << "Would you like to play again? [y/n]: ";
    char res;
    std::cin >> res;
    if (res == 'y') {
      ;
    } else if (res == 'n') {
      computer.print_score();
      player.print_score();
      if (computer.wins > player.wins) {
        std::cout << "Computer wins the most games LOSER!\n";
      } else {
        std::cout << "You won the most games!\n";
      }
      done = true;
    } else {
      std::cout << "Error: invalid input. Enter y for yes or n for no\n";
    }
  }
}
