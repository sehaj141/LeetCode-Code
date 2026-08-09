#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Custom comparator comparing squared Euclidean distance
        auto squaredDist = [](const vector<int>& p) {
            return p[0] * p[0] + p[1] * p[1];
        };
        
        // Reorders points so that the first k elements are the k smallest by distance
        nth_element(points.begin(), points.begin() + k, points.end(),
            [&squaredDist](const vector<int>& a, const vector<int>& b) {
                return squaredDist(a) < squaredDist(b);
            }
        );
        
        // Return the first k elements
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};