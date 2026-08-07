#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Initial answer: add/subtract k from all elements uniformly
        int ans = nums[n - 1] - nums[0];
        
        // Try splitting after index i
        for (int i = 0; i < n - 1; ++i) {
            int max_val = max(nums[i] + k, nums[n - 1] - k);
            int min_val = min(nums[0] + k, nums[i + 1] - k);
            
            ans = min(ans, max_val - min_val);
        }
        
        return ans;
    }
};