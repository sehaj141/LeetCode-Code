#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int last_end = -1; // End index of the last chosen palindrome

        // Helper to check if s[l...r] is a palindrome
        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };

        for (int r = k - 1; r < n; ++r) {
            // Check candidate palindrome of length k ending at r
            int l_k = r - k + 1;
            if (l_k > last_end && isPalindrome(l_k, r)) {
                count++;
                last_end = r;
                continue;
            }

            // Check candidate palindrome of length k + 1 ending at r
            int l_k1 = r - k;
            if (l_k1 > last_end && isPalindrome(l_k1, r)) {
                count++;
                last_end = r;
            }
        }

        return count;
    }
};