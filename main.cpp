#include <string.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "include/personal_info.hpp"
#include "include/pin_checker.hpp"

int main() {
  // ! temporal value for test;
  // TODO: read from database
  std::unordered_map<std::string, project::PersonalInfo> pin_db;
  pin_db["1111222233334441"] = project::PersonalInfo(100);
  pin_db["1111222233334442"] = project::PersonalInfo(200);
  pin_db["1111222233334443"] = project::PersonalInfo(300);
  pin_db["1111222233334444"] = project::PersonalInfo(50);
  pin_db["1111222233334445"] = project::PersonalInfo(0);

  auto pin_checker = project::PinChecker();
  pin_checker.set_db(pin_db);
  auto user = project::PersonalInfo();

  std::cout << "\n\n \t\t\t WELCOME \n\n";
  std::cout << "\n\n \t\tATM is started! \n\n\n\n";
  while (true) {
    std::string card;
    std::cout << "Please Insert Card: ";
    std::cin >> card;

    // match with known pin number from db
    if (pin_checker.find_pin(card) == false) {
      std::cout << "\t[ERROR] PIN number: " << card.length()
                << ". It must be 16 digits.\n";
      std::cout << "\tPlease retry\n";
      continue;
    }
    user = pin_checker.get_account_info(card);
    // user.set_id(pin_checker.get_account_info(card).get_id());
    // user.set_balance(pin_checker.get_account_info(card).get_balance());
    // user.set_pin(pin_checker.get_account_info(card).get_pin());
    break;
  }

  while (true) {
    int select_num = 0;
    std::cout << "Welcome " << user.get_id() << "\n";
    std::cout << "\tYour PIN Number : " << user.get_pin() << "\n";
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
        exit(1);
        break;
      case 2: {
        std::cout << "Please enter the deposit amound: ";
        int dollar = 0;
        // TODO: counting dollar
        std::cin >> dollar;
        if (dollar < 0) {
          std::cout << "[ERROR] This is not valid.\n";
          exit(1);
          break;
        }
        user.deposit(dollar);
        std::cout << "Your Balance : " << user.get_balance() << "\n";
        std::cout << "THANK YOU.\n";
        exit(1);
        break;
      }
      case 3: {
        std::cout << "Enter Withdraw Amount : ";
        int dollar = 0;
        std::cin >> dollar;

        if (user.get_balance() < dollar) {
          std::cout << "[ERROR] There is not enough money.\n";
          exit(1);
          break;
        }
        // TODO: utilizing std::future
        user.withdraw(dollar);
        std::cout << "Your Balance : " << user.get_balance() << "\n";
        std::cout << "THANK YOU.\n";
        exit(1);
        break;
      }
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