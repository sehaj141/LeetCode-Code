class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 0;

        // Helper function to expand outwards from a given center (left, right)
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // After loop, (left + 1) to (right - 1) is the valid palindrome
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < s.length(); i++) {
            expandAroundCenter(i, i);     // Check odd-length palindromes (e.g., "aba")
            expandAroundCenter(i, i + 1); // Check even-length palindromes (e.g., "abba")
        }

        return s.substr(start, maxLen);
    }
};