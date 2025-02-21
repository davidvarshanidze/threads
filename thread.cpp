#include <iostream>
#include <thread>

void print_message(const std::string& message) {
    std::cout << "Thread says: " << message << std::endl;
}

int main() {
    std::thread t1(print_message, "Hello from thread 1!");
    std::thread t2(print_message, "Hello from thread 2!");

    t1.join();  // Wait for t1 to finish
    t2.join();  // Wait for t2 to finish

    std::cout << "Both threads finished!" << std::endl;
    return 0;
}
