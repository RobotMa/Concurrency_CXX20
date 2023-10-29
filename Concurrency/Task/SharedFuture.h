#include <future>
#include <iostream>
#include <mutex>

std::mutex mut;

struct Sender {
  void operator()(std::promise<int> &&p, int costA, int costB) {
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    p.set_value(costB + costA);
  }
};

struct Requester {
  void operator()(std::shared_future<int> f) {

    {
      std::lock_guard lk(mut);
      std::cout << "Thread ID: " << std::this_thread::get_id() << '\n';
      std::cout << "Requester: " << f.get() << '\n';
    }
  }
};
