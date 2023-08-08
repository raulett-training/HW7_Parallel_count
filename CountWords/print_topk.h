//
// Created by raulett on 07.08.2023.
//

#ifndef PARALLEL_COUNT_PRINT_TOPK_H
#define PARALLEL_COUNT_PRINT_TOPK_H

#include "Counter.h"
#include "vector"

void print_topk(std::ostream& stream, const Counter&, size_t k);
std::vector<std::pair<std::string, std::size_t>> get_topk(const Counter& counter, size_t k);
#endif //PARALLEL_COUNT_PRINT_TOPK_H
