#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> pointSet;
        
        // Encode (x, y) into a single unique integer using coordinate limits (<= 40000)
        for (const auto& point : points) {
            pointSet.insert(point[0] * 40001 + point[1]);
        }
        
        int minArea = INT_MAX;
        int n = points.size();
        
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                
                // Check if (x1, y1) and (x2, y2) can form a valid diagonal
                if (x1 != x2 && y1 != y2) {
                    // Verify if the opposite corners (x1, y2) and (x2, y1) exist
                    if (pointSet.count(x1 * 40001 + y2) && pointSet.count(x2 * 40001 + y1)) {
                        int area = abs(x1 - x2) * abs(y1 - y2);
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        
        return minArea == INT_MAX ? 0 : minArea;
    }
};