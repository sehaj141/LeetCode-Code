#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // dp[i][M] stores max stones obtainable starting from pile i with parameter M
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        // suffixSum[i] = sum of piles[i...n-1]
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        // Fill DP table bottom-up from the last pile back to 0
        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                // If current player can take all remaining piles
                if (i + 2 * M >= n) {
                    dp[i][M] = suffixSum[i];
                } else {
                    for (int X = 1; X <= 2 * M; ++X) {
                        int nextM = max(M, X);
                        dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + X][nextM]);
                    }
                }
            }
        }
        
        return dp[0][1];
    }
};