#include <cassert>
#include <iostream>
#include <thread>
#include <unistd.h>

void function_with_arguments(int *i) {
    sleep(1);
    int c;
    c = *i + 2;
}

int main() {
    int f = 6;
    std::thread lambda_thread([]{
        std::cout << "Hi from lambda";
    });

    std::thread another_detached_lambda_thread(function_with_arguments, &f);


    lambda_thread.join();
    another_detached_lambda_thread.detach();
    return 0;
}
