class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;

        const int MOD = 1e9 + 7;
        
        // dp[r][c] stores the number of paths out of bounds from (r, c) with current remaining moves
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Build the solution layer by layer from move 1 to maxMove
        for (int k = 1; k <= maxMove; ++k) {
            vector<vector<int>> next_dp(m, vector<int>(n, 0));
            
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    for (auto& dir : directions) {
                        int nr = r + dir.first;
                        int nc = c + dir.second;
                        
                        // If moving in this direction goes out of bounds, add 1 path
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            next_dp[r][c] = (next_dp[r][c] + 1) % MOD;
                        } else {
                            // Otherwise, add the paths available from the neighbor in k-1 moves
                            next_dp[r][c] = (next_dp[r][c] + dp[nr][nc]) % MOD;
                        }
                    }
                }
            }
            dp = move(next_dp);
        }

        return dp[startRow][startColumn];
    }
};