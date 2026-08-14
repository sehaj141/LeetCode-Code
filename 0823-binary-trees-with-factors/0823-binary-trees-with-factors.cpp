#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        const int MOD = 1e9 + 7;
        std::sort(arr.begin(), arr.end());
        
        // dp[val] stores the number of valid binary trees with root = val
        std::unordered_map<int, long long> dp;
        long long totalTrees = 0;

        for (int i = 0; i < arr.size(); ++i) {
            long long ways = 1; // Single-node tree

            for (int j = 0; j < i; ++j) {
                int left = arr[j];
                // Optimization: If left * left > arr[i], remaining factors are redundant
                if ((long long)left * left > arr[i]) {
                    break;
                }

                if (arr[i] % left == 0) {
                    int right = arr[i] / left;
                    if (dp.count(right)) {
                        long long combinations = (dp[left] * dp[right]) % MOD;
                        
                        if (left == right) {
                            ways = (ways + combinations) % MOD;
                        } else {
                            // Account for both (left, right) and (right, left) subtrees
                            ways = (ways + combinations * 2) % MOD;
                        }
                    }
                }
            }

            dp[arr[i]] = ways;
            totalTrees = (totalTrees + ways) % MOD;
        }

        return totalTrees;
    }
};