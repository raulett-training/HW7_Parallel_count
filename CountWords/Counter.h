//
// Created by raulett on 07.08.2023.
//

#ifndef PARALLEL_COUNT_COUNTER_H
#define PARALLEL_COUNT_COUNTER_H

#include <string>
#include <map>
#include <atomic>

extern std::atomic<uint64_t> general;
using Counter = std::map<std::string, std::size_t>;

#endif //PARALLEL_COUNT_COUNTER_H
