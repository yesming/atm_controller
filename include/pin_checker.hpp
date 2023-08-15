
#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#include "personal_info.hpp"
namespace project {
class PinChecker {
 public:
  PinChecker() = default;
  ~PinChecker() = default;

  void set_db(const std::unordered_map<std::string, PersonalInfo>& pin_db);

  bool find_pin(const std::string& pin);

  PersonalInfo get_account_info(const std::string& pin);

 private:
  std::unordered_map<std::string, PersonalInfo> pin_db_;
};
}  // namespace project