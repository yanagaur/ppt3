#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();

    // Find the first element from the right that is smaller than its next element
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    // If such element exists, find the smallest element greater than it to its right
    if (i >= 0) {
        int j = n - 1;
        while (j > i && nums[j] <= nums[i]) {
            --j;
        }
        std::swap(nums[i], nums[j]);
    }

    // Reverse the subarray to the right of the current element
    std::reverse(nums.begin() + i + 1, nums.end());
}

void printArray(const std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i != nums.size() - 1)
            std::cout << ",";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {1, 2, 3};

    nextPermutation(nums);

    printArray(nums);

    return 0;
}
