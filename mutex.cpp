// mutex prevents race conditions

#include <iostream>
#include <thread>
#include <mutex>

int balance = 100;
std::mutex account_mutex;  // Protect shared resource

void withdraw(int amount) {
    std::lock_guard<std::mutex> lock(account_mutex);  // Lock resource
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Withdrew " << amount << ", New balance: " << balance << std::endl;
    } else {
        std::cout << "Not enough funds!" << std::endl;
    }
}

int main() {
    std::thread t1(withdraw, 70);
    std::thread t2(withdraw, 50);

    t1.join();
    t2.join();

    return 0;
}
