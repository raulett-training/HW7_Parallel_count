//
// Created by raulett on 08.08.2023.
//

#ifndef PARALLEL_COUNT_MERGECOUNTERS_H
#define PARALLEL_COUNT_MERGECOUNTERS_H

#include "ParallelQueue.h"
#include "Counter.h"

void MergeCounters(ParallelQueue<Counter>&, std::atomic<unsigned int>&);
#endif //PARALLEL_COUNT_MERGECOUNTERS_H
