#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
    std::vector<std::vector<int>> result;

    long long next = static_cast<long long>(lower);

    for (int num : nums) {
        if (num > next) {
            result.push_back({static_cast<int>(next), num - 1});
        }
        next = static_cast<long long>(num) + 1;
    }

    if (next <= upper) {
        result.push_back({static_cast<int>(next), upper});
    }

    return result;
}

void printRanges(const std::vector<std::vector<int>>& ranges) {
    for (const std::vector<int>& range : ranges) {
        std::cout << "[" << range[0] << "," << range[1] << "] ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    std::vector<std::vector<int>> result = findMissingRanges(nums, lower, upper);

    printRanges(result);

    return 0;
}
