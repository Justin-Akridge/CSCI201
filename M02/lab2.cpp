#include <iostream>
#include <cstdint>

/* Justin Akridge
 * 08/31/2023
 * This problem is test exception handling to see what errors we get 
 * when an invalid value is entered 
 * This program needs to be compiled with -std=c++17
 *
 * Conclusion: I only see a out_of_range error being throw from entering an
 * invalid response. In the case of an array, it would throw an overflow error
 * and when accessing an element that doesn't exist in the array, a range_error.
 */

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
      std::cout << "Byte value: " << static_cast<int>(byte_value) << std::endl;
    }
  } catch (const std::overflow_error &e) {
      std::cerr << "Overflow error: " << e.what() << std::endl;
  } catch (const std::range_error &e) {
      std::cerr << "Range error: " << e.what() << std::endl;
  } catch (const std::out_of_range &e) {
      std::cerr << "Out of range error: " << e.what() << std::endl;
  } catch (...) {
      std::cerr << "An unexpected error occured." << std::endl;
  }
  return 0;
}
