#include <vector>
#include <algorithm>

class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        // Sort by the relative benefit of choosing City A over City B
        std::sort(costs.begin(), costs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        
        int totalCost = 0;
        int n = costs.size() / 2;
        
        // First n people go to City A, next n people go to City B
        for (int i = 0; i < n; ++i) {
            totalCost += costs[i][0];       // City A
            totalCost += costs[i + n][1];   // City B
        }
        
        return totalCost;
    }
};