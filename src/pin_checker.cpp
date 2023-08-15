#include "../include/pin_checker.hpp"

namespace project {

void PinChecker::set_db(
    const std::unordered_map<std::string, PersonalInfo>& pin_db) {
  pin_db_ = pin_db;
}

bool PinChecker::find_pin(const std::string& pin) {
  if (pin_db_.find(pin) != pin_db_.end()) {
    return true;
  } else {
    return false;
  }
}

PersonalInfo PinChecker::get_account_info(const std::string& pin) {
  return pin_db_[pin];
}

}  // namespace project
