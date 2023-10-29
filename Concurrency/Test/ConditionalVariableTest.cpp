#include "Concurrency/ConditionVariableResource.h"

#include <thread>

#include <gtest/gtest.h>

TEST(ConditionVariableResourceTest, ConditionVariableResourceTest) {
  ConditionVariableResource cvr;

  std::jthread thread1(&ConditionVariableResource::updateData, &cvr);
  std::jthread thread2(&ConditionVariableResource::loadData, &cvr);

  thread1.join();
  thread2.join();
}

