//
// Created by raulett on 08.08.2023.
//

#include "MergeCounters.h"
#include  "Counter.h"

void MergeCounters(ParallelQueue<Counter>& queue, std::atomic<unsigned int>& is_working_flag){
    while (!queue.is_stopped()){
        Counter entry1, entry2;
        queue.pop_pair(entry1, entry2, is_working_flag);
        std::map<std::string, std::size_t>::iterator it;
        for (it = entry2.begin(); it!=entry2.end(); it++){
            entry1[it->first] = entry1[it->first] + it->second;
        }
        queue.push(std::move(entry1));
    }
}
