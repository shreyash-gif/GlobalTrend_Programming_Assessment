#include <iostream>
#include <vector>
#include <algorithm>

void rotateArray(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    rotateArray(nums, k);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
