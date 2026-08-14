#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        std::vector<int> count(26, 0);
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;

            // Shrink window from the left until no character appears > 2 times
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            // Update maximum valid substring length found so far
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};