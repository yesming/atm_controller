#include <string>
#include <vector>

namespace project {

class PersonalInfo {
 public:
  PersonalInfo() = default;
  ~PersonalInfo() = default;

  void set_id(std::string id) { id_ = id; };
  std::string get_id() { return id_; }

  int get_balance();
  void deposit(int dollar);
  void withdraw(int dollar);

 private:
  std::string id_ = "";

  int balance_ = 0;
};
}  // namespace project