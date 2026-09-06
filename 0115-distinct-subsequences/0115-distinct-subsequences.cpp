class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        
        // Use unsigned long long to prevent integer overflow during intermediate steps
        vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: empty string t can always be formed 1 way
        dp[0] = 1;
        
        for (int i = 1; i <= m; ++i) {
            // Traverse backwards to use values from the previous iteration of s
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        
        return dp[n];
    }
};