#include "Concurrency/Task/SharedFuture.h"

#include <future>
#include <iostream>
#include <thread>

#include <gtest/gtest.h>

TEST(SharedFutureTest, SharedFutureTest) {

  std::promise<int> p;
  std::shared_future f = p.get_future();

  // compute result in a separate thread
  std::jthread t(Sender(), std::move(p), 2, 3);

  // Request result in multiple threads concurrently
  std::jthread t1(Requester(), f);
  std::jthread t2(Requester(), f);

  t.join();
  t1.join();
  t2.join();
}