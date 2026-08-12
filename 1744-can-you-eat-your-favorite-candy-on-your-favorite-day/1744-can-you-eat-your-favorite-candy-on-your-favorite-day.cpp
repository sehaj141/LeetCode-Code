#include <vector>

class Solution {
public:
    std::vector<bool> canEat(std::vector<int>& candiesCount, std::vector<std::vector<int>>& queries) {
        int n = candiesCount.size();
        
        // Compute prefix sums of candy counts
        // pref[i] store total candies from type 0 up to type i-1
        std::vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + candiesCount[i];
        }

        std::vector<bool> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int type = q[0];
            long long day = q[1];
            long long cap = q[2];

            // Minimum candies you MUST eat before target day (1 candy/day)
            long long min_eaten = day + 1;
            
            // Maximum candies you CAN eat up to target day
            long long max_eaten = (day + 1) * cap;

            // Target candy range [first_candy, last_candy] (1-indexed index in total sequence)
            long long first_candy = pref[type] + 1;
            long long last_candy = pref[type + 1];

            // Check if intervals overlap
            // Overlap condition: min_eaten <= last_candy AND max_eaten >= first_candy
            ans.push_back(min_eaten <= last_candy && max_eaten >= first_candy);
        }

        return ans;
    }
};