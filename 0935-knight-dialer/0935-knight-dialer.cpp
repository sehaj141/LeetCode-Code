#include <vector>
#include <numeric>

class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;

        const int MOD = 1e9 + 7;

        // Current count of paths ending at each digit [0..9]
        std::vector<long long> dp(10, 1);

        for (int step = 2; step <= n; ++step) {
            std::vector<long long> next_dp(10, 0);

            next_dp[0] = (dp[4] + dp[6]) % MOD;
            next_dp[1] = (dp[6] + dp[8]) % MOD;
            next_dp[2] = (dp[7] + dp[9]) % MOD;
            next_dp[3] = (dp[4] + dp[8]) % MOD;
            next_dp[4] = (dp[0] + dp[3] + dp[9]) % MOD;
            next_dp[5] = 0;
            next_dp[6] = (dp[0] + dp[1] + dp[7]) % MOD;
            next_dp[7] = (dp[2] + dp[6]) % MOD;
            next_dp[8] = (dp[1] + dp[3]) % MOD;
            next_dp[9] = (dp[2] + dp[4]) % MOD;

            dp = std::move(next_dp);
        }

        long long total = 0;
        for (long long count : dp) {
            total = (total + count) % MOD;
        }

        return total;
    }
};