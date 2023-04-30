#include <iostream>

#include <chrono>

#define STP_POOL_IMPLEMENTATION
#include "stp.hpp"

int main() {
    auto start = std::chrono::steady_clock::now();
    {
    stp::pool pool{};


    for(int i = 0; i < 10000; i++) {
        pool.add_task([i] {
            double k = 68.0;
            for (double i = 1; i < 100000; i++) {
                k /= i;
            }
        });
    }

    //pool.~pool();

    }
    
    auto end = std::chrono::steady_clock::now();
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}
