#include <iostream>

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

  void set_play(std::string &new_play) {
    if (this->position == "quarterback") {
      play = new_play;
    }
  }
  
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

void call_get_player_position(Player *player) {
  std::cout << player->get_player_position() << '\n';
}

void call_get_play(Player *player) {
  std::cout << player->get_play();
}

int main() {
  Offense playerone();
  call_get_player_position(&playerone);
  call_get_play(&playerone);
}
