#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> charMap;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        if (charMap.find(s[end]) != charMap.end()) {
            start = std::max(charMap[s[end]] + 1, start);
        }
        charMap[s[end]] = end;
        maxLength = std::max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    std::string str = "abcabcbb";
    std::cout << "Length of longest substring without repeating characters: " 
              << lengthOfLongestSubstring(str) << std::endl;
    
    str = "bbbbb";
    std::cout << "Length of longest substring without repeating characters: " 
              << lengthOfLongestSubstring(str) << std::endl;
    
    str = "pwwkew";
    std::cout << "Length of longest substring without repeating characters: " 
              << lengthOfLongestSubstring(str) << std::endl;

    return 0;
}
