#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        long MOD = 1e9 + 7;
        
        sort(nums.begin(), nums.end());
        
        long ans = 0;
        long p2 = 1; // Tracks powers of 2 (2^i)
        
        for (int i = 0; i < n; ++i) {
            // nums[i] acts as max in 2^i subsequences
            // nums[n - 1 - i] acts as min in 2^i subsequences
            ans = (ans + (nums[i] - nums[n - 1 - i]) * p2) % MOD;
            p2 = (p2 * 2) % MOD;
        }
        
        // Handle negative modulo results in C++
        return (ans + MOD) % MOD;
    }
};