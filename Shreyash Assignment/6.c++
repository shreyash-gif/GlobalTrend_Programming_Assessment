#include <iostream>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int number = 10;  // Example number to find factorial
    unsigned long long fact = factorial(number);
    std::cout << "Factorial of " << number << " is: " << fact << std::endl;
    return 0;
}
