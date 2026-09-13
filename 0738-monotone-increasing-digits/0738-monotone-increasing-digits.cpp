#include <string>

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        std::string s = std::to_string(n);
        int marker = s.length(); // Index from which digits should be set to '9'

        // Scan from right to left
        for (int i = s.length() - 1; i > 0; --i) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                marker = i;
            }
        }

        // Fill all positions from marker onward with '9'
        for (int i = marker; i < s.length(); ++i) {
            s[i] = '9';
        }

        return std::stoi(s);
    }
};