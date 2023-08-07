#include <iostream>
#include <atomic>
#include "count_words.h"
#include <Windows.h>


std::atomic<uint64_t> general = 0;
const size_t TOPK = 10;

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);

    return 0;
}


