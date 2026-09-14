#include <string>
#include <algorithm>

class Solution {
public:
    int minFlipsMonoIncr(std::string s) {
        int ones_count = 0;
        int flips = 0;

        for (char c : s) {
            if (c == '1') {
                ones_count++;
            } else {
                // If we see a '0', we either:
                // 1. Flip this '0' to '1' -> flips + 1
                // 2. Flip all previous '1's to '0' -> ones_count
                flips = std::min(flips + 1, ones_count);
            }
        }

        return flips;
    }
};