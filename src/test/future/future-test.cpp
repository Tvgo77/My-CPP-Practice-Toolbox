#include <iostream>
#include <future>
//#include <thread>
#include <chrono>

int compute() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulating some computation
    return 42; // the answer to life, the universe, and everything
}

int main() {
    // Run compute asynchronously
    //std::future<int> result = std::async(std::launch::deferred, compute);
    std::future<int> result = std::async(std::launch::async, compute);


    // Do something else while compute is running
    std::cout << "Doing some other work..." << std::endl;

    // Get the result (will block if not ready)
    int value = result.get();
    std::cout << "Computed value: " << value << std::endl;

    return 0;
}
