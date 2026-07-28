#include <vector>
#include <algorithm>

class Solution {
public:
    int orderOfLargestPlusSign(int n, std::vector<std::vector<int>>& mines) {
        // Initialize n x n grid with 1s
        std::vector<std::vector<int>> grid(n, std::vector<int>(n, 1));
        
        // Mark mined cells as 0
        for (const auto& mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        
        // dp[i][j] stores the minimum continuous 1s in all 4 directions from cell (i, j)
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        
        // 1. Pass left-to-right and right-to-left
        for (int i = 0; i < n; ++i) {
            int left = 0, right = 0;
            for (int j = 0; j < n; ++j) {
                // Left-to-Right
                left = (grid[i][j] == 0) ? 0 : left + 1;
                dp[i][j] = left;
            }
            for (int j = n - 1; j >= 0; --j) {
                // Right-to-Left
                right = (grid[i][j] == 0) ? 0 : right + 1;
                dp[i][j] = std::min(dp[i][j], right);
            }
        }
        
        int maxOrder = 0;
        
        // 2. Pass top-to-bottom and bottom-to-top
        for (int j = 0; j < n; ++j) {
            int top = 0, bottom = 0;
            for (int i = 0; i < n; ++i) {
                // Top-to-Bottom
                top = (grid[i][j] == 0) ? 0 : top + 1;
                dp[i][j] = std::min(dp[i][j], top);
            }
            for (int i = n - 1; i >= 0; --i) {
                // Bottom-to-Top
                bottom = (grid[i][j] == 0) ? 0 : bottom + 1;
                dp[i][j] = std::min(dp[i][j], bottom);
                
                // Track the maximum order found across the entire grid
                maxOrder = std::max(maxOrder, dp[i][j]);
            }
        }
        
        return maxOrder;
    }
};