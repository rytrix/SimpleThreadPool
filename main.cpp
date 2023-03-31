#include <iostream>

#include <windows.h>

#define STP_POOL_IMPLEMENTATION
#include "stp.hpp"

int main() {

    stp::pool pool{};

    for(int i = 0; i < 100; i++) {
        pool.add_task([i] {
            std::cout << "Task " << i << " is running on thread " << std::this_thread::get_id() << std::endl;
            Sleep(1000);
        });
    }
    
    pool.~pool();

    std::cout << "Ending program" << std::endl;

    return 0;
}