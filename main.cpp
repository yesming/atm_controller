#include <string.h>

#include <iostream>
#include <string>
#include <vector>

#include "include/personal_info.hpp"
#include "include/pin_checker.hpp"

using namespace project;
int main() {
  //   uint64_t pin_number;
  char pin_number[16];
  auto user = PersonalInfo();

  std::cout << "\n\n \t\t\t WELCOME \n\n";
  std::cout << "\n\n \t\tATM is started! \n\n\n\n";
  while (true) {
    std::string card;
    std::cout << "Please Insert Card: ";
    std::cin >> card;

    // match with known pin number from db
    if (card.length() != 16) {
      std::cout << "\t[ERROR] PIN number: " << card.length()
                << ". It must be 16 digits.\n";
      std::cout << "\tPlease retry\n";
      continue;
    }
    user.set_id(card.c_str());
    user.deposit(10);
    strcpy(pin_number, card.c_str());
    break;
  }

  while (true) {
    int select_num = 0;
    std::cout << "\tYour PIN Number : " << pin_number << "\n";
    std::cout << "\t\t1. Account Balance Inquiry.\n";
    std::cout << "\t\t2. Deposit.\n";
    std::cout << "\t\t3. Withdraw.\n";
    std::cout << "\t\t4. Exit.\n";
    std::cin >> select_num;
    std::cout << "\n\n";
    if (select_num > 4 || select_num < 1) {
      std::cout << "[ERROR] The selected number is invalid.\nPlease "
                   "reselection.\n";
      continue;
    }

    switch (select_num) {
      case 1:
        std::cout << "Balance : " << user.get_balance() << "$.\n";
      case 2: {
        std::cout << "Enter Deposit Account : ";
        char deposit_account[16];
        // check
        // deposit_account
      }
      case 3:
      case 4:
        std::cout << "THANK YOU.\n";
        exit(1);
        break;
      default:
        std::cout << "[ERROR] UNKNOWN number.\n";
        exit(1);
        break;
    }
  }

  return 0;
}