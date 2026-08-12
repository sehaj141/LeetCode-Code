#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int kthLargestValue(std::vector<std::vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 2D Prefix XOR table
        std::vector<std::vector<int>> pref(m + 1, std::vector<int>(n + 1, 0));
        
        // Min-heap to maintain top k elements
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Formula: pref[i+1][j+1] = matrix[i][j] ^ pref[i][j+1] ^ pref[i+1][j] ^ pref[i][j]
                pref[i + 1][j + 1] = matrix[i][j] ^ pref[i][j + 1] ^ pref[i + 1][j] ^ pref[i][j];
                
                int val = pref[i + 1][j + 1];
                
                // Keep only top k elements in min-heap
                min_heap.push(val);
                if (min_heap.size() > k) {
                    min_heap.pop();
                }
            }
        }

        return min_heap.top();
    }
};