#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> quadruplets;
    int n = nums.size();

    if (n < 4)
        return quadruplets;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        ++left;

                    while (left < right && nums[right] == nums[right - 1])
                        --right;

                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }

    return quadruplets;
}

void printQuadruplets(const std::vector<std::vector<int>>& quadruplets) {
    for (const auto& quad : quadruplets) {
        std::cout << "[";
        for (int i = 0; i < 4; ++i) {
            std::cout << quad[i];
            if (i != 3)
                std::cout << ",";
        }
        std::cout << "]";
    }
}

int main() {
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    std::vector<std::vector<int>> result = fourSum(nums, target);

    printQuadruplets(result);

    return 0;
}
