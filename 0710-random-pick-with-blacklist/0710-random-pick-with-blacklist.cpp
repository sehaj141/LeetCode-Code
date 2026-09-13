#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>

class Solution {
private:
    int valid_range_size;
    std::unordered_map<int, int> remap;

public:
    Solution(int n, std::vector<int>& blacklist) {
        int b_size = blacklist.size();
        valid_range_size = n - b_size;

        // Store blacklisted elements >= valid_range_size for quick lookup
        std::unordered_set<int> blacklisted_in_upper;
        for (int b : blacklist) {
            if (b >= valid_range_size) {
                blacklisted_in_upper.insert(b);
            }
        }

        // Remap blacklisted elements < valid_range_size to available numbers in [valid_range_size, n - 1]
        int next_valid = valid_range_size;
        for (int b : blacklist) {
            if (b < valid_range_size) {
                while (blacklisted_in_upper.count(next_valid)) {
                    next_valid++;
                }
                remap[b] = next_valid++;
            }
        }
    }
    
    int pick() {
        int r = rand() % valid_range_size;
        auto it = remap.find(r);
        return (it != remap.end()) ? it->second : r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */