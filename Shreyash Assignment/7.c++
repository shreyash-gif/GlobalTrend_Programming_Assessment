#include <iostream>

int sumOfDigits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int number = 8122;
    int sum = sumOfDigits(number);
    std::cout << "Sum of digits of " << number << " is: " << sum << std::endl;
    return 0;
}
