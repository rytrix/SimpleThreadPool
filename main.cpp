#include <iostream>

#include <windows.h>
#include <chrono>

#define STP_POOL_IMPLEMENTATION
#include "stp.hpp"

int main() {

    stp::pool pool{};

    Sleep(1000);

    auto start = std::chrono::steady_clock::now();

    for(int i = 0; i < 10000; i++) {
        pool.add_task([i] {
            double k = 69;
            for (double i = 0; i < 100000; i++) {
                k /= i;
            }
        });
    }

    pool.~pool();
    
    auto end = std::chrono::steady_clock::now();
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}