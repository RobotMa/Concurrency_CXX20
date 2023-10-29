#include "SpinLockSleep.h"

#include <iostream>

void updateSharedCounts() {
  spinLock.lock();
  ++cnt;
  std::cout << "Current cnt is : " << cnt << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  spinLock.unlock();
}