#include <string.h>

#include <iostream>
#include <string>
#include <vector>

#include "include/pin_checker.hpp"
int main() {
  //   uint64_t pin_number;
  char pin_number[16];

  std::cout << "\n\n ----- WELCOME ----- \n\n";
  std::cout << "\n\n ATM is started! \n\n\n\n";
  while (true) {
    std::string card;
    std::cout << "Please Insert Card: ";
    std::cin >> card;

    // match with known pin number from db
    if (card.length() != 16) {
      std::cout << "[ERROR] PIN number: " << card.length()
                << ". It must be 16 digits.\n";
      continue;
    }
    strcpy(pin_number, card.c_str());
    break;
  }
  std::cout << pin_number;
  while (true) {
    break;
  }

  return 0;
}