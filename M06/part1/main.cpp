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
    player_number = 0;
  }

  Player(std::string init_name, int init_playerId) {
    name = init_name;
    player_number = init_playerId;
  }

  virtual void get_player_number_input() {
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
    player_number = converted_input_number;
    std::cout << '\n';
  }

  virtual void get_player_name_input() {
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
      }
    }
    name = player_name;
    std::cout << '\n';
  }

  virtual ~Player() {};
  virtual void set_play() {}
  virtual void set_player_position() {}

  virtual std::string to_string() const {
    return "Name: " + name + "\nPlayers number: " + std::to_string(player_number) + '\n';
  }
protected:
  std::string name;
  int player_number;
};

class Offense : public Player {
public:
  Offense() : Player() {
    position = "";
    play = "";
  }

  Offense(std::string init_name, int init_playerId, std::string init_position, std::string init_play) 
         : Player(init_name, init_playerId) {
    position = init_position;
    play = init_play;
  }

  void set_play() override {
    bool done = false;
    while (!done) {
      std::cout << "\nSelect a play\n";
      for (int i = 0; i < plays.size(); i++) {
        std::cout << "Press " << i+1 << " for " << plays[i] << '\n';
      }
      std::cout << "Selection: ";
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
        case '3':
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
        case '6':
          play = plays[5];
          done = true;
          break;
        case '7':
          play = plays[6];
          done = true;
          break;
        case '8':
          play = plays[7];
          done = true;
          break;
        case '9':
          play = plays[8];
          done = true;
          break;
        default:
          std::cerr << "Input is an invalid response. Please enter a number between 0-8";
      }
    }
  }

  void set_player_position() override {
    bool done = false;
    while (!done) {
      std::cout << "Select the position of the player\n";
      for (int i = 0; i < positions.size(); i++) {
        std::cout << "Press " << i+1 << " for " << positions[i] << '\n';
      }
      char input;
      std::cout << "Selection: ";
      std::cin >> input;
      std::cout << '\n';
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
        case '8':
          position = positions[7];
          done = true;
          break;
        default:
          std::cerr << "Input is an invalid response. Please enter a number between 0-8";
          break;
      }
    }
  }

  std::string to_string() const override {
    return Player::to_string() + "Position: " + position + "\nPlay: " + play + '\n';
   
  }
private:
  std::vector<std::string> positions = {"quarterback", "running back", "wide receiver", 
                                        "tight end", "offensive tackle", "offensive guard", 
                                        "center", "fullback"};
  std::vector<std::string> plays = {"inside run", "outside run", "draw play", "play action", 
                                    "screen pass", "slant route", "post route",
                                    "double pass", "hail mary"};
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

  void set_play() override {
    bool done = false;
    std::cout << "Select the defensive play\n";
    while (!done) {
      for (int i = 0; i < plays.size(); i++) {
        std::cout << "Press " << i + 1 << " for " << plays[i] << '\n';
      }
      std::cout << "Selection: ";
      char input;
      std::cin >> input;
      std::cout << '\n';
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

  void set_player_position() override {
    bool done = false;
    std::cout << "Select the position of the player\n";
    while (!done) {
      for (int i = 0; i < positions.size(); i++) {
        std::cout << "Press " << i + 1 << " for " << positions[i] << '\n';
      } 
      std::cout << "Selection: ";
      char input;
      std::cin >> input;
      std::cout << '\n';
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
        default:
          std::cerr << "You must enter a number between 1-7\n";
      }
    }
  }

  std::string to_string() const override{
    return Player::to_string() + "Position: " + this->position + "\nPlay: " + this->play + '\n';
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

  void set_play() override {
    bool done = false;
    while (!done) {
      for (int i = 0; i < plays.size(); i++) {
        std::cout << "Press " << i + 1 << " for " << plays[i] << '\n';
      }
      std::cout << "Selection: ";
      char input;
      std::cin >> input;
      std::cout << '\n';
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

  void set_player_position() override {
    bool done = false;
    std::cout << "Select the position of the player\n";
    while (!done) {
      for (int i = 0; i < positions.size(); i++) {
        std::cout << "Press " << i + 1 << " for " << positions[i] << '\n';
      }
      std::cout << "Selection: ";
      char input;
      std::cin >> input;
      std::cout << '\n';
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

  std::string to_string() const override {
    return Player::to_string() + "Position: " + position + "\nPlay: " + play + '\n';
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
  std::vector<Player*> players;
  while (!done) {
    char input;
    std::cout << "-----Create Roster-----\n"
                 "press 1 to add a offense player\n"
                 "press 2 to add a defense player\n"
                 "press 3 to add a special teams players\n"
                 "press 0  to quit\n";
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    if (input == '0') {
      done = true;
    } else if (input == '1') {
      Offense* offensive_player = new Offense();
      offensive_player->get_player_name_input();
      offensive_player->get_player_number_input();
      offensive_player->set_player_position();
      offensive_player->set_play();
      players.push_back(offensive_player);
    } else if (input == '2') {
      Defense* defensive_player = new Defense();
      defensive_player->get_player_name_input();
      defensive_player->get_player_number_input();
      defensive_player->set_player_position();
      defensive_player->set_play();
      players.push_back(defensive_player);
    } else if (input == '3') {
      Special_teams* special_teams_player = new Special_teams();
      special_teams_player->get_player_name_input();
      special_teams_player->get_player_number_input();
      special_teams_player->set_player_position();
      special_teams_player->set_play();
      players.push_back(special_teams_player);
    } else {
      std::cerr << "Input must be a number between 1-3\n";
    }
  }
  std::cout << "\n------Roster------\n";
  for (const auto& player: players) {
    std::string player_info = player->to_string();
    std::cout << player_info << std::endl;
  }
}
