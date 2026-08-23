#include <vector>
#include <algorithm>

class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        // Check triplets from largest to smallest
        for (int i = nums.size() - 1; i >= 2; --i) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        
        return 0;
    }
};