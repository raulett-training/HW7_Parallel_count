//
// Created by raulett on 07.08.2023.
//

#include <ostream>
#include <algorithm>
#include <iomanip>
#include "print_topk.h"

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
            std::begin(words), std::begin(words) + k, std::end(words),
            [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
            std::begin(words), std::begin(words) + k,
            [&stream](const Counter::const_iterator &pair) {
                stream << std::setw(4) << pair->second << " " << pair->first
                       << '\n';
            });
}

std::vector<std::pair<std::string, std::size_t>> get_topk(const Counter& counter, const size_t k){
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
            std::begin(words), std::begin(words) + k, std::end(words),
            [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::vector<std::pair<std::string, std::size_t>> result_vector;
    result_vector.reserve(k);
    for (size_t i=0; i<k; i++){
        result_vector.emplace_back(words[i]->first, words[i]->second);
    }

    return result_vector;
}