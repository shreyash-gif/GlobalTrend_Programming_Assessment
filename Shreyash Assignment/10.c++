#include <iostream>
#include <string>

bool isAlphabetic(const std::string& str) {
    for (char ch : str) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str1 = "HelloWorld";
    std::string str2 = "Hello123";

    std::cout << std::boolalpha; // Print bool values as true/false
    std::cout << "String '" << str1 << "' contains only alphabetic characters: " << isAlphabetic(str1) << std::endl;
    std::cout << "String '" << str2 << "' contains only alphabetic characters: " << isAlphabetic(str2) << std::endl;

    return 0;
}
