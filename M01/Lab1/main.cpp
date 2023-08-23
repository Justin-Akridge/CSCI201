#include <iostream>

class Math {
public:
    Math();
    int getInt();
    bool setInt(int x);
private:
    int value;
};

Math::Math() {
    value = 0;
}

int Math::getInt() {
    return value;
}

bool Math::setInt(int x) {
    if(x < 0)
        return -1;
    else
        value = x;
    return 0;
}

int main() {
    Math test;
    if(test.setInt(5345) == 0)
        std::cout << test.getInt() << '\n';
    else
        std::cout << "Invalid Input\n";
}