#include <iostream>
#include <future>

int calculate_sum(int a, int b) {
    return a + b;
}

int main() {
    std::future<int> result = std::async(std::launch::async, calculate_sum, 10, 20);

    std::cout << "Doing other work...\n";

    int sum = result.get();  // Wait for result
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
