#include <condition_variable>
#include <mutex>
#include <vector>

class ConditionVariableResource {
private:
  std::mutex mut_;
  std::vector<int> vec_;
  std::condition_variable cv_;

public:
  void updateData();

  void loadData();
};