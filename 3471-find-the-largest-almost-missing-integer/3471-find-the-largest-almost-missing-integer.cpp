#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k == 1 -> Find the largest number with total count == 1 in nums
        if (k == 1) {
            unordered_map<int, int> count;
            for (int x : nums) count[x]++;
            int ans = -1;
            for (auto& [val, cnt] : count) {
                if (cnt == 1) ans = max(ans, val);
            }
            return ans;
        }

        // Case 2: k == n -> Only 1 subarray exists (the entire array). Return max element.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n -> Only nums[0] or nums[n-1] can be almost missing
        unordered_map<int, int> count;
        for (int x : nums) count[x]++;

        int ans = -1;
        // nums[0] appears in only 1 size-k subarray if it is unique in nums
        if (count[nums[0]] == 1) ans = max(ans, nums[0]);
        // nums[n-1] appears in only 1 size-k subarray if it is unique in nums
        if (count[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);

        return ans;
    }
};