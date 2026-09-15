#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        // Push all boundary land cells into the queue
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) { grid[i][0] = 0; q.push({i, 0}); }
            if (grid[i][n - 1] == 1) { grid[i][n - 1] = 0; q.push({i, n - 1}); }
        }
        for (int j = 1; j < n - 1; ++j) {
            if (grid[0][j] == 1) { grid[0][j] = 0; q.push({0, j}); }
            if (grid[m - 1][j] == 1) { grid[m - 1][j] = 0; q.push({m - 1, j}); }
        }

        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        // Multi-source BFS from boundary
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }

        // Count remaining enclaves
        int enclaves = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};