#include <iostream>

int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    bool good_number = true;
    for (int i = 0; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            std::cout << "You entered an invalid character in postion: " << i+1 << '\n';
            good_number = false;
        }
    }
    if (good_number)
        std::cout << "You entered a good number\n";
}