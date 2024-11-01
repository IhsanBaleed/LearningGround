#include "Threads.hh"
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <future>


std::string input_prompt = "Please enter a value";

void MyClass::Do_something(int val) {
    while (true) {
        std::cout << "Doing Something" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void MyClass::operator() (int var) {
    while (true) {
        std::cout << "Functor called" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void MyClass::static_method() {
    while (true) {
        std::cout << "Static Method Called" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

auto my_lambda = [](int values) {
    while (true) {
        std::cout << "Lambda Called" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
};

void operate() {
    while (true) {
        std::cout << "I am operating" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

std::mutex m;
void sum_up(int val, std::string calling_thread) {
    static int total = 0;
        while (true) {
        m.lock();
        total += val;
        std::cout << calling_thread << ": is incrementing" << " -- Value total: " << total << std::endl;
        m.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

std::condition_variable cv; // used to send a signal between threads
std::mutex mutx; // will be shared between a unique_lock and a lock_guard
int shared_val = 0;
void worker_process(int id) {

    std::lock_guard<std::mutex> lock(mutx); // forces mutual exclusion between for threads using the same mutex

    std::cout << "Worker Process: " << id << " Has completed" << std::endl;

    while (shared_val < 8) {
        shared_val += id;
        cv.notify_one(); // wakes up one thread that waits on it
    }
}
bool check_value(){
    return shared_val > 7;
}
void child_process() {
    std::unique_lock<std::mutex> unique_lock(mutx); // forces mutual exclusion between for threads using the same mutex
    cv.wait(unique_lock, check_value);              // will call the function when first called, and when the condition becomes true
    std::cout << "Child process running" << std::endl;
}

void alpha_process(std::promise<int>&& the_promise) {
    std::cout << "alpha is processing" << std::endl;
    the_promise.set_value(7); // notifies the thread attached to this promise
}

void beta_process(std::future<int> && the_future) {
    std::cout << "beta getting ready" << std::endl;
    int val = the_future.get(); // waits until the promise is fullfiled 
    std::cout << "beta is processing, got val: " << val << std::endl;
}

void test_threads_1() {
    
    std::cout << input_prompt << std::endl;

    int input;
    std::cin >> input;

    std::thread t1(operate); // they accept functions as an argument.

    // if this function finishes before the thread is joined, it will segfault 
    // because the destructor is called without proper joining.
    // join() will force the caller of the thread to wait until the thread finishes its work.
    t1.join();

    // std::thread* thread_ptr = new std::thread(operate);
}

void test_threads_2() {
    // the arguemnts for a function must be passed to the thread
    std::thread t1(sum_up,1, "t1");
    
    // we can call it with lambda values too
    std::thread t2(my_lambda, 2);

    // we can call it with functors too
    std::thread t3(MyClass(), 3);

    // can be called with a method of a class
    // must pass the reference of the class and object to the thread.
    MyClass objl;
    int x;
    std::thread t4(&MyClass::Do_something, &objl, x);

    // can also be called with static methods of a class
    // no need to pass an object though.
    std::thread t5(&MyClass::static_method);



    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join(); // the thread stops when join is called.

    std::cout << "End of test" << std::endl;
}

void test_threads_3() {

    // whichever thread gets to the mutex first, will look the others out
    // when it unlocks, the others can proceed.
    std::thread t1(sum_up, 2, "t1");
    std::thread t2(sum_up, 3, "t2");

    t1.join();
    t2.join();
}

void test_threads_4() {

    std::thread t1(child_process);
    std::thread t2(worker_process, 1);

    t1.join();
    t2.join();

}

void test_thread_5() {

    std::promise<int> the_promise;
    std::future<int> the_future = the_promise.get_future(); // this attaches the two

    std::thread t2(beta_process, std::move(the_future));
    std::thread t1(alpha_process, std::move(the_promise));

    t1.join();
    t2.join();

    std::cout << "End of test" << std::endl;
}


