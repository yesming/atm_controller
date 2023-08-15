#include <string>
#include <vector>

namespace project {

class PersonalInfo {
 public:
  PersonalInfo() = default;
  ~PersonalInfo() = default;

  void set_id(std::string id) { id_ = id; };
  string get_id() { return id_; }

 private:
  std::string id_;
};
}  // namespace project