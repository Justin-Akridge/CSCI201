#include <unordered_map>
#include <iostream>
#include <string>
#include <cassert>
#include <random>

//#include <sqlite3>

using namespace std;

class bank {
public:
  bank() = delete;
  bank(double);
  int login();
  int get_shiftKey() const;
private:
  double balance;
  double credit_line;
  std::unordered_map<int, int> account;
  int shift_key;
};

bank::bank(double balance_) {
  assert(balance_ > 500);
  if (balance_ < 0) {
    std::cerr << "Cannot open account with negative value";
    exit(1);
  } else if (balance_ < 500) {
    std::cerr << "500$ is required to open up a new account";
    exit(1);
  }
  balance = balance_;
  credit_line = 0;
  generate_shift_key();
}

std::string encrypt(const std::string& ciphertext, int shift) {
  std::string decrypt_text;
  for (char c : ciphertext) {
    if (std::isalpha(c)) {
      char decrypted_char = c - shift;
      decrypted_char += 26;
      decrypt_text += decrypted_char;
    } else {
      decrypt_text += c;
    }
  }
  return decrypt_text;
}

std::string decrypt(const std::string& ciphertext, int shift) {
  std::string decrypted_text;
  for (char c : ciphertext) {
    if (!(std::isdigit(c))) {
      char decrypted_char = c + shift;
      decrypted_char -= 26;
      decrypted_text += decrypted_char;
    } else {
      decrypted_text += c;
    }
  }
  return decrypted_text;
}

int bank::get_shiftKey() const {
  return shift_key; 
}

void bank::generate_shift_key() {
  using my_engine = default_random_engine;
  using my_distribution = uniform_int_distribution<>;

  my_engine end {};
  my_distribution dist {1, 6};

  auto die = [&](){ return dist(end); };

  int x = die();

  bank.shift_key = x;
}

int bank::login() {
  std::cout << "Login: ";
  std::string username;
  std::cin >> username;

  std::cout << "Password: ";
  std::string password;
  std::cin >> password;
}

int main() {  
  // generate shift key for encryption
  std::string s = encrypt("Justin", 1);
  std::cout << s << '\n';
  std::string t = decrypt(s, 1);
  std::cout << t << '\n';

TODO: finish implementing this function
  bank b(1000);
  std::cout << b.get_shiftKey << std::endl;
  

}
