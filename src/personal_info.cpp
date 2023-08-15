#include "../include/personal_info.hpp"

namespace project {

int PersonalInfo::get_balance() { return balance_; }

void PersonalInfo::deposit(int dollar) { balance_ += dollar; }

void PersonalInfo::withdraw(int dollar) { balance_ -= dollar; }
}  // namespace project