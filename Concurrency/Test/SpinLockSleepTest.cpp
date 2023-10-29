#include "Concurrency/SpinLockSleep.h"

#include <thread>

#include <gtest/gtest.h>

TEST(SpinLockSleepTest, SpinLockSleepTest) {
  std::jthread thread1(updateSharedCounts);
  std::jthread thread2(updateSharedCounts);

  thread1.join();
  thread2.join();
}