#include <vector>
#include <algorithm>

class Solution {
private:
    int memo[50][50][50];

    int solve(int r1, int c1, int r2, const std::vector<std::vector<int>>& grid, int n) {
        int c2 = r1 + c1 - r2;

        // Out of bounds or hit a thorn
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || 
            grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1e9; // Large negative number to represent invalid path
        }

        // Reached destination: bottom-right corner
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        // Return cached result if already computed
        if (memo[r1][c1][r2] != -1) {
            return memo[r1][c1][r2];
        }

        // Cherries collected at the current step
        int cherries = 0;
        if (r1 == r2 && c1 == c2) {
            cherries = grid[r1][c1];
        } else {
            cherries = grid[r1][c1] + grid[r2][c2];
        }

        // Explore all 4 possible move combinations for (P1, P2):
        // 1. Down, Down
        // 2. Down, Right
        // 3. Right, Down
        // 4. Right, Right
        int maxNext = std::max({
            solve(r1 + 1, c1, r2 + 1, grid, n),
            solve(r1 + 1, c1, r2, grid, n),
            solve(r1, c1 + 1, r2 + 1, grid, n),
            solve(r1, c1 + 1, r2, grid, n)
        });

        cherries += maxNext;

        return memo[r1][c1][r2] = cherries;
    }

public:
    int cherryPickup(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::fill(&memo[0][0][0], &memo[0][0][0] + sizeof(memo) / sizeof(int), -1);

        int result = solve(0, 0, 0, grid, n);
        
        // If result is negative, no valid path exists
        return std::max(0, result);
    }
};