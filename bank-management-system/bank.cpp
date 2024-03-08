#include "bank.h"

bank::bank(double balance_, double credit_line_) {
  if (balance < 0) {
    std::cerr << "Cannot open account with negative value";
    exit(1);
  } else if (balance < 500) {
    std::cerr << "500$ is required to open up a new account";
    exit(1);
  }
  balance = balance_;
  credit_line = 0;
}



//bank::application_for_credit(int credit_score, int credit_history) {
//  
//}
