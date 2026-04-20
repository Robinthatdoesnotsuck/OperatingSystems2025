#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

// Global or shared mutex to protect the file resource
std::mutex fileMutex;

void writeToFile(int threadId, const std::string& filename) {
    // 1. Lock the mutex before opening/writing
    // std::lock_guard automatically releases the mutex when it goes out of scope
    std::lock_guard<std::mutex> lock(fileMutex);

    // 2. Open the file in append mode
    std::ofstream outFile(filename, std::ios::app);

    if (outFile.is_open()) {
        outFile << "Thread " << threadId << " is writing to the file." << std::endl;
        
        // Simulating some work
        std::cout << "Thread " << threadId << " finished writing." << std::endl;
        
        // 3. File closes automatically when outFile goes out of scope
    } else {
        std::cerr << "Error: Could not open file from thread " << threadId << std::endl;
    }
}

int main() {
    const std::string filename = "output.txt";
    const int numThreads = 2;
    std::vector<std::jthread> threads;

    // Launching threads
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(writeToFile, i, filename);
    }

    // No need to manually join jthreads; they handle it on destruction.
    std::cout << "Main thread: All writing tasks dispatched." << std::endl;

    return 0;
}