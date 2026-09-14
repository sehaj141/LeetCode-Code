#include <vector>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int best_prev = matrix[r - 1][c];
                
                if (c > 0) {
                    best_prev = std::min(best_prev, matrix[r - 1][c - 1]);
                }
                if (c + 1 < n) {
                    best_prev = std::min(best_prev, matrix[r - 1][c + 1]);
                }
                
                matrix[r][c] += best_prev;
            }
        }
        
        return *std::min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};