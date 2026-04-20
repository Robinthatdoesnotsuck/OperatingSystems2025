#include <iostream>
#include <thread>
#include <syncstream> // Required for std::osyncstream

void print_something() {
    for(int i = 0; i < 100; i++) {
        // Wrap cout in a synchronized stream for this scope
        std::osyncstream bout(std::cout); 
        bout << "A" << "B" << "C" << std::endl;
    } 
} // bout is destroyed here, flushing "ABC\n" all at once

void print_other_thing() {
    for(int i = 0; i < 100; i++) {
        // Also use osyncstream here to respect the synchronization
        std::osyncstream bout(std::cout);
        bout << "1" << "2" << "3" << std::endl;
    }
}

int main() {
    std::thread one_thread(print_something);
    std::thread two_thread(print_other_thing);
    
    one_thread.join();
    two_thread.join();
    
    return 0;
}