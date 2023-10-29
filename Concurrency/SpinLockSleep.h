#include <thread>
#include <atomic>

static int cnt{0};

class SpinLock {

private:
  std::atomic_flag flag_{ATOMIC_FLAG_INIT};

public:
  SpinLock() = default;

  void lock() {
    while(flag_.test_and_set());
  }

  void unlock() {
    flag_.clear();
  }

};

SpinLock spinLock;

void updateSharedCounts();