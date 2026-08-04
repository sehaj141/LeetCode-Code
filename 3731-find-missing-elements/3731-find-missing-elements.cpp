#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<int> findMissingElements(std::vector<int>& nums) {
        if (nums.empty()) return {};

        // Find min and max boundaries in the array
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        int min_val = *min_it;
        int max_val = *max_it;

        // Store numbers in a hash set for fast lookup
        std::unordered_set<int> seen(nums.begin(), nums.end());
        std::vector<int> result;

        // Collect all integers within [min_val, max_val] that are missing
        for (int x = min_val + 1; x < max_val; ++x) {
            if (seen.find(x) == seen.end()) {
                result.push_back(x);
            }
        }

        return result;
    }
};