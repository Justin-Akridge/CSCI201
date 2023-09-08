#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>

int main() {
  std::unordered_set<std::string> words;
  std::unordered_set<std::string>::iterator itr;
  std::ifstream myfile ("input.txt");
  if (myfile.is_open()) {
    while (myfile.good()) {
      std::string word;
      myfile >> word;
      if(words.count(word) >= 1) {
        std::cerr << "word is already in the set" << '\n';
      } else {
       words.insert(word); 
      }
    }
  }
  myfile.close();
  for (itr = words.begin(); itr != words.end(); itr++) {
    std::cout << *itr << '\n';
  } 
}
