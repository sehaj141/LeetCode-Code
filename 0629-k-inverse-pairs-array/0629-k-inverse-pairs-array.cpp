class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == 0) return 1;

        const int MOD = 1e9 + 7;
        
        // dp[j] stores the number of permutations of current length with j inverse pairs
        vector<int> dp(k + 1, 0);
        dp[0] = 1; // Base case: 1 permutation of length 1 with 0 inverse pairs

        for (int i = 1; i <= n; ++i) {
            vector<int> next_dp(k + 1, 0);
            long long window_sum = 0;

            for (int j = 0; j <= k; ++j) {
                window_sum += dp[j];

                // Remove the element that falls outside the sliding window of size i
                if (j >= i) {
                    window_sum -= dp[j - i];
                }

                // Apply modulo arithmetic safely
                window_sum = (window_sum % MOD + MOD) % MOD;
                next_dp[j] = window_sum;
            }

            dp = move(next_dp);
        }

        return dp[k];
    }
};