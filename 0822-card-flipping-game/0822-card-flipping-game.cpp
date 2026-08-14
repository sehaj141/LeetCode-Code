#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

class Solution {
public:
    int flipgame(std::vector<int>& fronts, std::vector<int>& backs) {
        std::unordered_set<int> same;
        int n = fronts.size();

        // Step 1: Collect all numbers that appear on both sides of the same card
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }

        int min_val = INT_MAX;

        // Step 2: Find the minimum number among all cards that is not forbidden
        for (int i = 0; i < n; ++i) {
            if (!same.count(fronts[i])) {
                min_val = std::min(min_val, fronts[i]);
            }
            if (!same.count(backs[i])) {
                min_val = std::min(min_val, backs[i]);
            }
        }

        return (min_val == INT_MAX) ? 0 : min_val;
    }
};