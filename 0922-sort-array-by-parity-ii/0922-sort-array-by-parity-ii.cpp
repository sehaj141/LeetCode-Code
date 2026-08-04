#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
        int even_idx = 0;
        int odd_idx = 1;
        int n = nums.size();

        while (even_idx < n && odd_idx < n) {
            // Find an odd number at an even index
            while (even_idx < n && nums[even_idx] % 2 == 0) {
                even_idx += 2;
            }
            // Find an even number at an odd index
            while (odd_idx < n && nums[odd_idx] % 2 != 0) {
                odd_idx += 2;
            }

            // Swap them to put both in their correct places
            if (even_idx < n && odd_idx < n) {
                std::swap(nums[even_idx], nums[odd_idx]);
            }
        }

        return nums;
    }
};