#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> ones1, ones2;

        // Collect coordinates of all 1s
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.emplace_back(r, c);
                if (img2[r][c] == 1) ones2.emplace_back(r, c);
            }
        }

        // Count frequency of each translation vector (dr, dc)
        // Since -n < dr, dc < n, encode (dr, dc) as a single integer
        std::unordered_map<int, int> shift_count;
        int max_overlap = 0;

        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                int dr = r2 - r1;
                int dc = c2 - c1;
                int key = dr * 100 + dc; // Unique hash for -30 <= dr, dc <= 30
                max_overlap = std::max(max_overlap, ++shift_count[key]);
            }
        }

        return max_overlap;
    }
};