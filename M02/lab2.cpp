#include <iostream>
#include <cstdint>

//This program needs to be compiled with clang for std::byte 

int main() {
  try {
    while (true) {
      std::cout << "Enter a value for a byte: ";
      uint16_t input_value;
      std::cin >> input_value; 
      if (input_value < 0 || input_value > 255) {
        throw std::out_of_range("Value is out of range of a byte");
      }
      std::byte byte_value = static_cast<std::byte>(input_value);
      byte_value = byte_value + std::byte(1);
      std::cout << "Byte value: " << static_cast<int>(byte_value) << std::endl;
    }
  } catch (const std::out_of_range &e) {
      std::cerr << "Out of range error: " << e.what() << std::endl;
  } catch (const std::range_error &e) {
      std::cerr << "Range error: " << e.what() << std::endl;
  } catch (const std::overflow_error &e) {
      std::cerr << "Overflow error: " << e.what() << std::endl;
  } catch (...) {
      std::cerr << "An unexpected error occured." << std::endl;
  }
  return 0;
}
