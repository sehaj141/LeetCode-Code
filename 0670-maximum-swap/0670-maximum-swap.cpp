#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumSwap(int num) {
        std::string s = std::to_string(num);
        std::vector<int> last(10, -1);

        // Record the last occurrence of each digit
        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - '0'] = i;
        }

        // Find the first digit that can be swapped with a larger digit appearing later
        for (int i = 0; i < s.size(); ++i) {
            for (int d = 9; d > s[i] - '0'; --d) {
                if (last[d] > i) {
                    std::swap(s[i], s[last[d]]);
                    return std::stoi(s);
                }
            }
        }

        return num;
    }
};