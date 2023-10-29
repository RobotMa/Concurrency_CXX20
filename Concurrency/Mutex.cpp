#include <iostream>
#include <mutex>
#include <thread>

std::mutex mut;

void workOnResource(){
  mut.lock();
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  mut.unlock();
  std::cout << "Work done" << std::endl;
}

int main() {

  unsigned int n = std::jthread::hardware_concurrency();

  std::cout << "Number of hardware threads: " << n << std::endl;

  std::jthread t(workOnResource);
  std::jthread t2(workOnResource);

  return 0;
}