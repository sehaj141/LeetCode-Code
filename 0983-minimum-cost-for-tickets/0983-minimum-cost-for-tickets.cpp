#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        int last_day = days.back();
        std::unordered_set<int> travel_days(days.begin(), days.end());
        
        // dp[i] represents the minimum cost to travel up to day i
        std::vector<int> dp(last_day + 1, 0);

        for (int i = 1; i <= last_day; ++i) {
            // If we don't travel today, the cost is the same as yesterday
            if (travel_days.find(i) == travel_days.end()) {
                dp[i] = dp[i - 1];
                continue;
            }

            // Choose the cheapest pass that covers today
            int cost_1  = dp[std::max(0, i - 1)] + costs[0];
            int cost_7  = dp[std::max(0, i - 7)] + costs[1];
            int cost_30 = dp[std::max(0, i - 30)] + costs[2];

            dp[i] = std::min({cost_1, cost_7, cost_30});
        }

        return dp[last_day];
    }
};