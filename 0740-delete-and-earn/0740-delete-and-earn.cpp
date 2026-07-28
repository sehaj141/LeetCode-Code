#include <vector>
#include <algorithm>

class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxVal = *std::max_element(nums.begin(), nums.end());
        std::vector<int> points(maxVal + 1, 0);
        
        // Sum up total points possible for each value
        for (int num : nums) {
            points[num] += num;
        }
        
        int skip = 0; // Maximum points without taking points[i]
        int take = 0; // Maximum points including points[i]
        
        for (int i = 0; i <= maxVal; ++i) {
            int currentTake = skip + points[i];
            int currentSkip = std::max(skip, take);
            
            take = currentTake;
            skip = currentSkip;
        }
        
        return std::max(skip, take);
    }
};