#include <vector>

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j] represents the number of playlists of length i containing j unique songs
        std::vector<std::vector<long long>> dp(goal + 1, std::vector<long long>(n + 1, 0));
        
        // Base case: 0 songs played with 0 unique songs
        dp[0][0] = 1;
        
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 1. Play a new unique song: (n - (j - 1)) choices
                dp[i][j] = (dp[i - 1][j - 1] * (n - (j - 1))) % MOD;
                
                // 2. Replay an already played song: (j - k) choices, valid only if j > k
                if (j > k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
                }
            }
        }
        
        return dp[goal][n];
    }
};