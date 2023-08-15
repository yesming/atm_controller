#include "../include/personal_info.hpp"

namespace project {
PersonalInfo::PersonalInfo(int balance) {
  balance_ = balance;
  pin_ = "";
  id_ = "Jone Doe";
}
int PersonalInfo::get_balance() { return balance_; }
void PersonalInfo::set_balance(int balance) { balance_ = balance; }

void PersonalInfo::deposit(int dollar) { balance_ += dollar; }

void PersonalInfo::withdraw(int dollar) { balance_ -= dollar; }
}  // namespace project