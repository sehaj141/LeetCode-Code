#include <vector>

class Solution {
private:
    bool isSelfDividing(int num) {
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            // A self-dividing number cannot contain 0,
            // and must be divisible by every digit it contains.
            if (digit == 0 || num % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }

public:
    std::vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> result;
        for (int num = left; num <= right; ++num) {
            if (isSelfDividing(num)) {
                result.push_back(num);
            }
        }
        return result;
    }
};