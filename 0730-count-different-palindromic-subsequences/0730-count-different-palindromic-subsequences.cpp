#include <string>
#include <vector>

class Solution {
public:
    int countPalindromicSubsequences(std::string s) {
        int n = s.length();
        const int MOD = 1e9 + 7;
        
        // dp[i][j] stores the number of distinct palindromic subsequences in s[i...j]
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        
        // Base case: Single character substrings
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Process substrings of length 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    int low = i + 1;
                    int high = j - 1;
                    
                    // Find the first and last occurrence of s[i] inside the inner substring s[i+1...j-1]
                    while (low <= high && s[low] != s[i]) low++;
                    while (low <= high && s[high] != s[j]) high--;
                    
                    if (low > high) {
                        // Case 1: No occurrence of s[i] inside s[i+1...j-1]
                        // e.g., "a...a" with no 'a' in between
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % MOD;
                    } else if (low == high) {
                        // Case 2: Exactly one occurrence of s[i] inside s[i+1...j-1]
                        // e.g., "a...a...a"
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % MOD;
                    } else {
                        // Case 3: More than one occurrence of s[i] inside s[i+1...j-1]
                        // e.g., "a...a...a...a"
                        dp[i][j] = (dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1]) % MOD;
                    }
                } else {
                    // Outer characters do not match
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]) % MOD;
                }
                
                // Ensure non-negative modulo result
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
        }
        
        return dp[0][n - 1];
    }
};