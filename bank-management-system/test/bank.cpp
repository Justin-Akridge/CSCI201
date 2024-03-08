#include <unordered_map>
#include <iostream>
#include <string>
#include <cassert>
//#include <sqlite3>

using namespace std;
class bank {
public:
  bank() = delete;
  bank(double);
  int login();
private:
  double balance;
  double credit_line;
  std::unordered_map<int, int> account;
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

int bank::login() {
  std::cout << "Login: ";
  std::string username;
  std::cin >> username;

  std::cout << "Password: ";
  std::string password;
  std::cin >> password;
}

int main() {  
  std::string s = encrypt("Justin", 1);
  std::cout << s << '\n';
  std::string t = decrypt(s, 1);
  std::cout << t << '\n';
}
