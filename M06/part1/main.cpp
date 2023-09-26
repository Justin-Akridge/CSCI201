#include <iostream>
#include <vector>
#include <variant>
#include <string> 
#include <unordered_map>

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

  std::string get_name() const {
    return name;
  }

  int get_playerId() const {
    return playerId;
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

  void get_new_player_position() {

  }

  void set_play(std::string &new_play) {
    if (this->position == "quarterback") {
      play = new_play;
    }
  }
  ~Offense() {}; 
  std::string get_player_position() {
    return position;
  }
  
  std::string get_play() {
    return play;
  }

  std::string to_string() {
    std::string s = "Position: " + position + "\nPlay: " + play + '\n';
    return s;
  }
private:
  std::vector<std::string> positions = {"quarterback", "running back", "wide reciever",
                                        
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

  void set_play(std::string init_play) {
    position = init_play;
  }

  std::string get_play() const {
    return play;
  }

  void set_position(std::string init_position) {
    position = init_position;
  }

private:
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

  void set_play(std::string init_play) {
    position = init_play;
  }

  std::string get_play() const {
    return play;
  }

  void set_position(std::string init_position) {
    position = init_position;
  }
private:
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
  char input;
  std::cout << "-----Create Roster-----\npress 1 to add a offense player\npress 2 to add a defense player\n";
               "press 3 to add a special teams players\n";
  std::cin >> input;
  switch (input) {
    case '1':
      std::string name = get_player_name();
      int number = get_player_number();
      std::string position = get_player_position();
      std::string play = get_play();
      
  }
  Offense new_offense_player("Justin Akridge", 88, "quarterback", "pass");
  Defense new_defense_player("Jimmy Jones", 42, "tackle", "Blitz");
  Special_teams new_special_team_player("wille doo", 24, "Kicker", "Field Goal");
}
