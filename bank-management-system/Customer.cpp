
Customer::Customer() {
  //maybe implement temporary encripted username and password
  username = "";
  password = "";
  pin = 0000;
  balance = 1000;
  savings = 0.0;
  credit = 0.0;
}

//Customer::~Customer();

int Customer::withdraw(double withdraw_amount) {
  if (withdraw_amount <= 5) {
    std::cerr << "Withdraw amount must be greater then $5.00\n;
  } else if (withdraw_amount >= 5000) {
    std::cerr << "Withdraw amount exceeds the maximum withdraw amount."
                 "Please request a bank representative in the display menu to fulfill your request";
  } else if (balance - withdraw_amount < 100) {
    std::cerr << "Your request cannot be fulfilled. Your withdraw ammount exceeds the"
                 "amount in your balance.";
  } else {
    balance -= withdraw_amount;
  }
} 

void Customer::deposit(double deposit_amount);
double Customer::get_loan();
void Customer::set_username();
void Customer::set_password();
void Customer::reset_password();

double Customer::get_balance() const {
  return balance;
}

void alert_balance() {
  std::cerr << "You have overdrawn your account. Your current balance is: "  << balance << '\n'; 
}

  std::string username;
  std::string password;
  int pin;
  double balance;
  double savings;
  double credit;
