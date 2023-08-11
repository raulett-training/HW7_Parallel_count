#include <iostream>
#include <atomic>
#include "count_words.h"
#include "print_topk.h"
//#include <Windows.h>
#include <chrono>
#include <fstream>
#include <future>
#include <list>
#include "ParallelQueue.h"
#include "MergeCounters.h"
#include "locale"


//std::atomic<uint64_t> general = 0;
const size_t TOPK = 10;
const size_t iteration_count = 1;

int main(int argc, char *argv[]) {
//    SetConsoleOutputCP(CP_UTF8);
    std::locale::global(std::locale("en_US.UTF-8"));
    std::cout<< "make: " << iteration_count << " repeat for each algorithm." <<std::endl;
    auto total_time = std::chrono::milliseconds(0);
    std::cout<< "-----sequential algorithm-------"<<std::endl;
    std::list<Counter> result_list;
    Counter freq_dict;
    std::cout << "iteration num of " << iteration_count << ": " << std::endl;
    for (size_t k=0; k<iteration_count; k++) {
        std::cout << k+1 << ", ";
        auto start = std::chrono::high_resolution_clock::now();
        freq_dict = Counter();
        for (int i = 1; i < argc; i++) {
            std::ifstream input{argv[i]};
            if (!input.is_open()) {
                std::cerr << "Failed to open file " << argv[i] << '\n';
                return EXIT_FAILURE;
            }
            count_words(input, freq_dict);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        total_time += elapsed_ms;
    }
    std::cout << std::endl;

    print_topk(std::cout, freq_dict, TOPK);
    result_list.push_back(freq_dict);
    std::cout << "total time for " << iteration_count << " iteration is: " << total_time << std::endl;
    std::cout << "average time for " << iteration_count << " iteration is: " << total_time/iteration_count << std::endl;

    std::cout<< "---end sequential algorithm-----\n"<<std::endl;
    std::cout<< "-----parallel algorithm-------"<<std::endl;


    total_time = std::chrono::milliseconds(0);
    std::vector<std::future<void>> tasks;
    tasks.reserve(argc-1);
    std::cout << "iteration num of " << iteration_count << ": " << std::endl;
    for (size_t k=0; k<iteration_count; k++) {
        std::cout << k+1 << ", ";
        ParallelQueue<Counter> queue;
        freq_dict = Counter();
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 1; i < argc; i++) {
            std::ifstream input{argv[i]};
            if (!input.is_open()) {
                std::cerr << "Failed to open file " << argv[i] << '\n';
                return EXIT_FAILURE;
            }
            tasks.push_back(std::async(std::launch::async,
                                       [stream = std::move(input), &queue]()mutable {
                Counter local_counter;
                count_words(stream, local_counter);
                queue.push(std::move(local_counter));
            }));
        }
        size_t num_threads = std::thread::hardware_concurrency();
        std::atomic<unsigned int> is_working_count = 0;
        std::vector<std::thread> merge_workers;
        merge_workers.reserve(num_threads);
        for (size_t i=0; i<num_threads; i++){
            is_working_count++;
            merge_workers.emplace_back([&queue, &is_working_count]()mutable {
                                                    MergeCounters(queue, is_working_count);});
        }

        for(int i = 0; i<argc-1; i++){
            tasks[i].wait();
        }

        while(is_working_count>0){}
        queue.pop(freq_dict);
        queue.stop();
        for(size_t i=0; i < merge_workers.size(); i++){
            merge_workers[i].join();
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        total_time += elapsed_ms;
        result_list.push_back(freq_dict);
    }
    std::cout << std::endl;
    print_topk(std::cout, freq_dict, TOPK);
    std::cout << "total time for " << iteration_count << " iteration is: " << total_time << std::endl;
    std::cout << "average time for " << iteration_count << " iteration is: " << total_time/iteration_count << std::endl;

    std::cout<< "---end parallel algorithm-----\n"<<std::endl;

    std::cout<< "---check for race condition-----"<<std::endl;
    std::cout<< "checking equality of sequential result and parallel algorithm results..." << std::endl;
    Counter reference_counter = result_list.front();
    result_list.pop_front();
    size_t diff_counter = 0;
    for(Counter counter:result_list){
        std::map<std::string, std::size_t>::iterator it;
        for(it = counter.begin(); it!=counter.end(); it++){
            if (reference_counter[it->first] != counter[it->first]){
                diff_counter++;
                break;
            }
        }
    }
    if (diff_counter == 0){
        std::cout << "there is no race condition detected" << std::endl;
    } else{
        std::cout << "there is race condition detected. "
        << diff_counter << " differences in results" << std::endl;
    }
    std::cout<< "---end check for race condition-----"<<std::endl;
    return 0;
}


