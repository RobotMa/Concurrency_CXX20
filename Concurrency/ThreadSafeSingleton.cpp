#include <iostream>
#include <memory>
#include <mutex>

class Singleton {
public:
  static Singleton *getInstance() {
    std::lock_guard lk(mut_);
    if (instance_ == nullptr) {
      instance_ = new Singleton;
    }
    return instance_;
  }

  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

protected:
  ~Singleton() = default;
  friend std::unique_ptr<Singleton>;

private:
  inline static Singleton*instance_ = nullptr;
  inline static std::mutex mut_;
  Singleton() = default;
};

int main() {

  std::cout << "Trying to create the 1st singleton : "
            << Singleton::getInstance() << '\n';
  std::cout << "Trying to create the 2nd singleton : "
            << Singleton::getInstance() << '\n';

  std::cout << "Program finished \n";

  return 0;
}