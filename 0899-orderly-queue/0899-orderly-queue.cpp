#include <string>
#include <algorithm>

class Solution {
public:
    std::string orderlyQueue(std::string s, int k) {
        if (k > 1) {
            // With k > 1, we can form any permutation, so sort s lexicographically.
            std::sort(s.begin(), s.end());
            return s;
        }

        // When k == 1, find the lexicographically smallest rotation.
        std::string min_str = s;
        for (int i = 1; i < s.length(); ++i) {
            // Rotate string by shifting the first character to the end
            std::string rotated = s.substr(i) + s.substr(0, i);
            if (rotated < min_str) {
                min_str = rotated;
            }
        }

        return min_str;
    }
};