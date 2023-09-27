#include <iostream>
#include <vector>
#include <string> 
#include <unordered_map>
#include <cctype>
#include <limits>

class Player {
public:
  Player() {
    name = "";
    playerId = 0;
  }

  Player(std::string init_name, int init_playerId) {
    name = init_name;
    playerId = init_playerId;
  }

  void set_player_name(std::string player_name) {
    name = player_name;
  }

  std::string get_name() const {
    return name;
  }

  int get_playerId() const {
    return playerId;
  }

  void set_playerId(int number) {
    playerId = number;
  }
  
  void get_player_number_input() {
    std::string input_number;
    int converted_input_number;
    bool done = false;
    while (!done) {
      std::cout << "Enter the number of the player: ";
      std::cin >> input_number;
      bool is_valid_int = true;
      for (int i = 0; i < input_number.size(); i++) {
        if (!std::isdigit(input_number[i])) {
          std::cerr << "Input must a be a number\n";
          done = false;
        }
      }
      if (is_valid_int) {
        converted_input_number = std::stoi(input_number);
        if (converted_input_number < 0 || converted_input_number > 100) {
          std::cerr << "Players number must be between 0 and 100\n";
        } else {
          done = true;
        }
      }
    }
    std::cout << '\n';
    set_playerId(converted_input_number);
  }

  std::string get_player_name_input() {
    std::string player_name;
    std::string first_name;
    std::string last_name;
    bool done = false;
    while (!done) {
      std::cout << "Enter the first and last name of the player: ";
      std::cin >> first_name >> last_name;
      player_name = first_name + " " + last_name;
      bool is_valid_name = true;
      for (int i = 0; i < player_name.size(); i++) {
        if (!std::isalpha(player_name[i]) && !std::isspace(player_name[i])) {
          is_valid_name = false;
          std::cerr << "Player name must have only characters between a-z\n";
        }
      }
      if (is_valid_name) {
        done = true;
        std::cout << player_name << std::endl;
        set_player_name(player_name);
      }
    }
    return player_name;
  }

  virtual ~Player() {};
  virtual std::string get_player_position() = 0;
  virtual std::string get_play() = 0;

  std::string to_string() {
    //this may need to return the position of the player
    std::string print = "Name: " + name + "\nPlayers number: " + std::to_string(playerId) + '\n';
    return print;
  }
private:
  std::string name;
  int playerId;
};

class Offense : public Player {
public:
  Offense() {
    position = "";
    play = "";
  }

  Offense(std::string init_name, int init_playerId, std::string init_position, std::string init_play) 
         : Player(init_name, init_playerId) {
    position = init_position;
    play = init_play;
  }

  ~Offense() {}; 

  void set_play() {
    bool done = false;
    while (!done) {
      std::cout << "\nSelect a play\n";
      for (int i = 0; i < plays.size(); i++) {
        std::cout << "Press " << i+1 << " for " << plays[i] << '\n';
      }
      std::cout << "Selection: ";
      std::string key_input;
      std::cin >> key_input;
      bool is_valid_int = true;
      for (auto i : key_input) {
        if (!std::isdigit(i)) {
          is_valid_int = false;
        }
      }
      if (is_valid_int) {
        int key = std::stoi(key_input);  
        switch (key) {
          case 1:
            play = plays[0];
            done = true;
            break;
          case 2:
            play = plays[1];
            done = true;
            break;
          case 3:
            play = plays[2];
            done = true;
            break;
          case 4:
            play = plays[3];
            done = true;
            break;
          case 5:
            play = plays[4];
            done = true;
            break;
          case 6:
            play = plays[5];
            done = true;
            break;
          case 7:
            play = plays[6];
            done = true;
            break;
          case 8:
            play = plays[7];
            done = true;
            break;
          case 9:
            play = plays[8];
            done = true;
            break;
          case 10:
            play = plays[9];
            done = true;
            break;
          default:
            std::cerr << "Input is an invalid response. Please enter a number between 0-8";
        }
      }
    }
  }

  std::string get_player_position() {
    return position;
  }

  void set_player_position() {
    bool done = false;
    while (!done) {
      std::cout << "Select the position of the player\n";
      for (int i = 0; i < positions.size(); i++) {
        std::cout << "Press " << i+1 << " for " << positions[i] << '\n';
      }
      std::cout << "Selection: ";
      std::string key_input;
      std::cin >> key_input;
      bool is_valid_int = true;
      for (auto i : key_input) {
        if (!std::isdigit(i)) {
          is_valid_int = false;
        }
      }
      if (is_valid_int) {
        int key = std::stoi(key_input);
        switch (key) {
          case 1:
            position = positions[0];
            done = true;
            break;
          case 2:
            position = positions[1];
            done = true;
            break;
          case 3:
            position = positions[2];
            done = true;
            break;
          case 4:
            position = positions[3];
            done = true;
            break;
          case 5:
            position = positions[4];
            done = true;
            break;
          case 6:
            position = positions[5];
            done = true;
            break;
          case 7:
            position = positions[6];
            done = true;
            break;
          case 8:
            position = positions[7];
            done = true;
            break;
            std::cerr << "Input is an invalid response. Please enter a number between 0-8";
        }
      } else {
        std::cout << "Input is an invalid response. Please enter a number between 0-8";
      }
    }
  }
  
  std::string get_play() {
    return play;
  }

  std::string to_string() {
    std::string s = "Position: " + position + "\nPlay: " + play + '\n';
    return s;
  }
private:
  std::vector<std::string> positions = {"quarterback", "running back", "wide receiver", 
                                        "tight end", "offensive tackle", "offensive guard", 
                                        "center", "fullback"};
  std::vector<std::string> plays = {"inside run", "outside run", "draw play", "play action", 
                                    "screen pass", "slant route", "post route",
                                    "bootleg", "double pass", "hail mary"};
  std::string position;
  std::string play;
};

class Defense : public Player {
public:
  Defense() {
    position = "";
    play = "";
  }

  Defense(std::string init_name, int init_playerId, std::string init_position, std::string init_play)
    : Player(init_name, init_playerId) {
    position = init_position;
    play = init_play;
  }

  std::string get_player_position() {
    return position;
  }
  
  std::string get_play() {
    return play;
  }

  void set_play() {
    bool done = false;
    while (!done) {
      for (int i = 0; i < plays.size(); i++) {
        std::cout << "Press " << i + 1 << " for " << plays[i] << '\n';
      }
      char input;
      std::cin >> input;
      switch (input) {
        case '1':
          play = plays[0];
          done = true;
          break;
        case '2':
          play = plays[1];
          done = true;
          break;
        case'3':
          play = plays[2];
          done = true;
          break;
        case '4':
          play = plays[3];
          done = true;
          break;
        case '5':
          play = plays[4];
          done = true;
          break;
        case'6':
          play = plays[5];
          done = true;
          break;
        case'7':
          play = plays[6];
          done = true;
          break;
        default:
          std::cout << "Invalid argument: Input must be a number between 1-7\n";
          break;
      }
    }
  }

  void set_player_position() {
    bool done = false;
    while (!done) {
      for (int i = 0; i < positions.size(); i++) {
        std::cout << "Press " << i + 1 << " for " << positions[i] << '\n';
      } 
      char input;
      std::cin >> input;
      switch (input) {
        case '1':
          position = positions[0];
          done = true;
          break;
        case '2':
          position = positions[1];
          done = true;
          break;
        case '3':
          position = positions[2];
          done = true;
          break;
        case '4':
          position = positions[3];
          done = true;
          break;
        case '5':
          position = positions[4];
          done = true;
          break;
        case '6':
          position = positions[5];
          done = true;
          break;
        case '7':
          position = positions[6];
          done = true;
          break;
      }
    }
  }

  std::string get_play() const {
    return play;
  }

  void set_position(std::string init_position) {
    position = init_position;
  }

private:
  std::vector<std::string> positions = {"defensive tackle", "defensive end", 
              "linebacker", "cornerback", "safety", "nickelback", "dimeback"}; 

  std::vector<std::string> plays = {"4-3", "3-4", "Cover 2", "Cover 3", "Cover 4", 
                                    "Man-to_man", "Zone Blitz"};

  std::string position;
  std::string play; 
};

class Special_teams : public Player {
public:
  Special_teams() {
    position = "";
    play = "";
  }

  Special_teams(std::string init_name, int init_playerId, std::string init_position, std::string init_play)
    : Player(init_name, init_playerId) {
    position = init_position;
    play = init_play;
  }

  std::string get_player_position() {
    return position;
  }
  
  std::string get_play() {
    return play;
  }

  void set_play() {
    bool done = false;
    while (!done) {
      for (int i = 0; i < plays.size(); i++) {
        std::cout << "Press " << i + 1 << " for " << plays[i] << '\n';
      }
      char input;
      switch (input) {
        case '1':
          done = true;
          play = plays[0];
          break;
        case '2':
          done = true;
          play = plays[1];
          break;
        case '3':
          done = true;
          play = plays[2];
          break;
        case '4':
          done = true;
          play = plays[3];
          break;
        case '5':
          done = true;
          play = plays[4];
          break;
        case '6':
          done = true;
          play = plays[5];
          break;
        case '7':
          done = true;
          play = plays[6];
          break;
        case '8':
          done = true;
          play = plays[7];
          break;
        case '9':
          done = true;
          play = plays[8];
          break;
        default:
          std::cerr << "Input must be a number between 1-9\n";
      }
    }
  }

  void set_player_position() {
    bool done = false;
    while (!done) {
      for (int i = 0; i < positions.size(); i++) {
        std::cout << "Press " << i + 1 << " for " << positions[i] << '\n';
      }
      char input;
      std::cin >> input;
      switch(input) {
        case '1':
          position = positions[0];
          done = true;
          break;
        case '2':
          position = positions[1];
          done = true;
          break;
        case '3':
          position = positions[2];
          done = true;
          break;
        case '4':
          position = positions[3];
          done = true;
          break;
        case '5':
          position = positions[4];
          done = true;
          break;
        case '6':
          position = positions[5];
          done = true;
          break;
        case '7':
          position = positions[6];
          done = true;
          break;
        case '8':
          position = positions[7];
          done = true;
          break;
        case '9':
          position = positions[8];
          done = true;
          break;
        default:
          std::cerr << "Input must be a number between 1-9\n";
      }
    }
  }

  std::string get_play() const {
    return play;
  }

private:
  std::vector<std::string> positions = {"kicker", "placekicker", "punter", "long snapper", 
                                        "holder", "kick returner", "punt returner",
                                        "gunner", "upback"};
  std::vector<std::string> plays = {"kickoff", "kickoff return", "onside kick", "field goal", 
                "extra point (PAT)", "two-point conversion", "punt", "punt-return", "fake-punt"};
  std::string position;
  std::string play; 
};

void call_get_player_position(Player *player) {
  std::cout << player->get_player_position() << '\n';
}

void call_get_play(Player *player) {
  std::cout << player->get_play();
}

std::string get_player_name() {
  std::string name;
  std::cout << "Enter the name of the player: ";
  std::cin >> name;
  return name;
}

int get_player_number() {
  bool done = false;
  std::string number;
  while (!done) {
    std::cout << "Enter the number of the player: ";
    std::cin >> number;
    std::cout << '\n';
    bool is_valid_int = true;
    for (int i = 0; i < number.size(); i++) {
      if (!std::isdigit(number[i])) {
        is_valid_int = false;  
      }
    }
    if (is_valid_int) {
      done = true;
    }
  }
  return std::stoi(number);
}


int main() {
  bool done = false;
  while (!done) {
    char input;
    std::cout << "-----Create Roster-----\npress 1 to add a offense player\n"
                 "press 2 to add a defense player\npress 3 to add a special teams players\n";
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    if (input == '1') {
      Offense offensive_player;
      offensive_player.Player::get_player_name_input();
      offensive_player.Player::get_player_number_input();
      offensive_player.set_player_position();
      offensive_player.set_play();
    } else if (input == '2') {
      Defense defensive_player;
      defensive_player.Player::get_player_name_input();
      defensive_player.Player::get_player_number_input();
      defensive_player.set_player_position();
      defensive_player.set_play();
    } else if (input == '3') {
      Special_teams special_teams_player;
      special_teams_player.Player::get_player_name_input();
      special_teams_player.Player::get_player_number_input();
      special_teams_player.set_player_position();
      special_teams_player.set_play();
    } else {
      std::cerr << "Input must be a number between 1-3\n";
    }
  }
}
