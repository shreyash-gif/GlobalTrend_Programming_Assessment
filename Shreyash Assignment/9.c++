#include <iostream>
#include <vector>
#include <climits>

int maxDifference(std::vector<int>& nums) {
    if (nums.empty() || nums.size() < 2) {
        return 0;
    }
    
    int minElement = INT_MAX;
    int maxDiff = INT_MIN;

    for (int num : nums) {
        if (num < minElement) {
            minElement = num;
        } else {
            int currentDiff = num - minElement;
            if (currentDiff > maxDiff) {
                maxDiff = currentDiff;
            }
        }
    }

    return maxDiff;
}

int main() {
    std::vector<int> nums = {7, 1, 5, 3, 6, 4};
    int maxDiff = maxDifference(nums);
    std::cout << "Maximum difference between any two elements: " << maxDiff << std::endl;
    return 0;
}
