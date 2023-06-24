#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();

    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            ++digits[i];
            return digits;
        } else {
            digits[i] = 0;
        }
    }

    digits.insert(digits.begin(), 1);
    return digits;
}

void printArray(const std::vector<int>& digits) {
    for (int i = 0; i < digits.size(); ++i) {
        std::cout << digits[i];
        if (i != digits.size() - 1)
            std::cout << ",";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> digits = {1, 2, 3};

    std::vector<int> result = plusOne(digits);

    printArray(result);

    return 0;
}
