#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <cfloat>

using namespace std;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        // Key: "midX,midY,squaredDist" -> Value: vector of point index pairs
        unordered_map<string, vector<pair<int, int>>> diagonalGroups;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long midX = points[i][0] + points[j][0];
                long long midY = points[i][1] + points[j][1];
                
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                long long distSq = dx * dx + dy * dy;
                
                string key = to_string(midX) + "," + to_string(midY) + "," + to_string(distSq);
                diagonalGroups[key].push_back({i, j});
            }
        }
        
        double minArea = DBL_MAX;
        
        for (const auto& [key, pairs] : diagonalGroups) {
            if (pairs.size() < 2) continue;
            
            // Check all pairs of diagonals that share the same midpoint and length
            for (size_t i = 0; i < pairs.size(); ++i) {
                for (size_t j = i + 1; j < pairs.size(); ++j) {
                    int p1 = pairs[i].first;
                    int p2 = pairs[j].first;
                    int p3 = pairs[j].second;
                    
                    // Side 1: dist(p1, p2), Side 2: dist(p1, p3)
                    long long dx1 = points[p1][0] - points[p2][0];
                    long long dy1 = points[p1][1] - points[p2][1];
                    double side1 = sqrt(dx1 * dx1 + dy1 * dy1);
                    
                    long long dx2 = points[p1][0] - points[p3][0];
                    long long dy2 = points[p1][1] - points[p3][1];
                    double side2 = sqrt(dx2 * dx2 + dy2 * dy2);
                    
                    minArea = min(minArea, side1 * side2);
                }
            }
        }
        
        return minArea == DBL_MAX ? 0.0 : minArea;
    }
};