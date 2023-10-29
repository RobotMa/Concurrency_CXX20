#include "Concurrency/ConditionVariableResource.h"

#include <iostream>

void ConditionVariableResource::updateData() {

  {
    std::unique_lock lk(mut_);
    std::cout << "Waiting for data to be loaded" << '\n';
    cv_.wait(lk, [this]{return !vec_.empty();});
    vec_[1] = 2;
  }

  {
    std::scoped_lock lk(mut_);
    std::cout << "Data updated" << '\n';
  }
}

void ConditionVariableResource::loadData() {
  {
    std::lock_guard lk(mut_);
    vec_ = {1, 0, 3};
  }

  cv_.notify_one();

  {
    std::scoped_lock lk(mut_);
    std::cout << "Data loaded" << '\n';
  }
}