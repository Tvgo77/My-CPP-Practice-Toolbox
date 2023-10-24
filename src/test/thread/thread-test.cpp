#include <thread>
#include <stdio.h>
#include <vector>

void myThreadfunc(int n) {
    printf("Thread %d\n", n);
}

int main() {
    std::vector<std::thread> threads;

    int numThreads = 4;
    for (int i = 0; i < numThreads; i++)
        threads.emplace_back(myThreadfunc, i + 1);

    for (int i = 0; i < numThreads; i++) 
        threads[i].join();

    return 0;
}