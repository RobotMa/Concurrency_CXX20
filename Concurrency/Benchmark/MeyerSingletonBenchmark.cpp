#include "Concurrency/MeyerSingleton.h"

#include <future>
#include <vector>

#include <benchmark/benchmark.h>

static void BM_SingletonCreationThreadSafe(benchmark::State &state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(Singleton::getInstance());
  }
}

BENCHMARK(BM_SingletonCreationThreadSafe)->Threads(1);
BENCHMARK(BM_SingletonCreationThreadSafe)->Threads(2);
BENCHMARK(BM_SingletonCreationThreadSafe)->Threads(4);
BENCHMARK(BM_SingletonCreationThreadSafe)->Threads(8);

static void BM_SingletonCreationMeyerAsync(benchmark::State &state) {
  for (auto _ : state) {

    std::vector<std::future<void>> futures;

    for (int i = 0; i < state.range(0); ++i) {
      futures.emplace_back(std::async(std::launch::async, []() {
        benchmark::DoNotOptimize(Singleton::getInstance());
      }));
    }

    for (auto &future : futures) {
      future.get();
    }

  }
}

BENCHMARK(BM_SingletonCreationMeyerAsync)->Arg(1)->Arg(2)->Arg(4)->Arg(8);

BENCHMARK_MAIN();