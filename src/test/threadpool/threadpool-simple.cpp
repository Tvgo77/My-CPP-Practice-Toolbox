#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <stdio.h>
#include <functional>
#include <condition_variable>

#define EVENT0 0
#define EVENT1 1
#define EVENT2 2

struct myEvent {
    int eventNum;
    void* eventSource;
};

class ThreadPool {
  private:
    std::vector<std::thread> threads;
    std::queue<myEvent> eventQueue;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;

  public:
    ThreadPool(size_t threadNum) {
        std::function<void()> func = std::bind(&ThreadPool::threadInitCall, this);
        for (int i = 0; i < threadNum; i++) {
            threads.emplace_back(func);
        }
    }

    void threadInitCall() {
        /* While eventQueue not empty, allocate event handling to thread */
        while (true) {
            struct myEvent event;
            {   // Mutex lock block
                std::unique_lock<std::mutex> lock(queueMutex);
                // This line can only be unblocked by condition notify when eventQueue isn't empty
                condition.wait(lock, [this](){return !eventQueue.empty() || stop;});
                if(stop && eventQueue.empty())
                    return;
                event = std::move(eventQueue.front());
                eventQueue.pop();
            }
            int err = eventHandle(event);
        }
    }

    int eventHandle(struct myEvent& event) {
        switch (event.eventNum) {
            case EVENT0:
                printf("Event0 occurred\n");
                break;
            case EVENT1:
                printf("Event1 occurred\n");
                break;
            case EVENT2:
                printf("Event2 occurred\n");
                break;
            default:
                break;
        }
        return 0;
    } 

    void enqueue(struct myEvent& event) {
        /* Lock the queue when add event*/
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            eventQueue.emplace(event);
        }
        /* When added a event, notify one thread */
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for(std::thread &t: threads)
            t.join();
    }
};

int main() {
    ThreadPool pool(4);
    std::vector<myEvent> eventList;
    eventList.push_back({0, NULL});
    eventList.push_back({1, NULL});
    eventList.push_back({2, NULL});
    for (myEvent& event: eventList) 
        pool.enqueue(event);

    return 0;
}