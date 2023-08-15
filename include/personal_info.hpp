#pragma once

#include <string>
#include <vector>

namespace project {

class PersonalInfo {
 public:
  PersonalInfo() = default;
  PersonalInfo(int balance);
  ~PersonalInfo() = default;

  PersonalInfo& operator=(const PersonalInfo& source) {
    if (this == &source) {
      return *this;
    }
    this->id_ = source.id_;
    this->pin_ = source.pin_;
    this->balance_ = source.balance_;

    return *this;
  }
  void set_id(std::string id) { id_ = id; };
  std::string get_id() { return id_; }

  void set_pin(const std::string& pin) { pin_ = pin; };
  std::string get_pin() { return pin_; };

  int get_balance();
  void set_balance(int balance);
  void deposit(int dollar);
  void withdraw(int dollar);

 private:
  std::string id_ = "Jone Doe";
  std::string pin_ = "";

  int balance_ = 0;
};
}  // namespace project