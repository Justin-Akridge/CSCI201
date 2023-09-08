#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

void print(const std::string &word) {
  std::cout << word << '\n';  
}

int main() {
  std::set<std::string> words;
  std::set<std::string>::iterator itr;
  std::ifstream myfile ("input.txt");
  if (myfile.is_open()) {
    while (myfile.good()) {
      std::string word = "";
      myfile >> word;
      if (word[0] == '.') {
        word = word.substr(1, word.size()-1);
      } else if (word[word.size()-1] == '.') {
        word = word.substr(0, word.size()-1);
      } 
      for (auto& i : word) {
        i = std::tolower(i);
      }
      if (words.count(word) >= 1) {
        std::cerr << "error: " << "{ " << word << " }" << " is already in the set.\n";
      } else {
        words.insert(word); 
      }
    }
  }
  myfile.close();
  std::for_each(words.begin(), words.end(), &print);
}
