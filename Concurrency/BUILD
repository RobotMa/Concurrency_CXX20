load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
    name = "SpinLockSleep",
    srcs = ["SpinLockSleep.cpp"],
    hdrs = ["SpinLockSleep.h"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "Mutex",
    srcs = ["Mutex.cpp"],
)

cc_library(
    name = "ConditionalVariable",
    srcs = ["ConditionVariableResource.cpp"],
    hdrs = ["ConditionVariableResource.h"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "ThreadSafeSingleton",
    srcs = ["ThreadSafeSingleton.cpp"],
)

cc_library(
    name = "MeyerSingleton",
    hdrs = ["MeyerSingleton.h"],
    visibility = ["//visibility:public"],
)
