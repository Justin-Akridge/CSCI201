#include <iostream>
#include <stdexcept>
#include <cstddef>

/*out of range
 * range error
 * overflow error
 * */
int main() {
  bool valid_byte = false;
  do {
    try {
      int8_t b;
      std::cout << "Enter a number between -127 and 127: ";
        throw b;
      }
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << '\n';
    } catch (const std::range_error& e) {
        std::cerr << "range error: " << e.what() << '\n';
    } catch (const std::overflow_error& e) {
        std::cerr << "Overflow error: " << e.what() << '\n';
    }
  } while (!valid_byte);
}
