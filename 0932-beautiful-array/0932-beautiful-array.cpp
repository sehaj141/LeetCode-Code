#include <vector>

class Solution {
public:
    std::vector<int> beautifulArray(int n) {
        std::vector<int> res = {1};
        
        while (res.size() < n) {
            std::vector<int> next;
            next.reserve(res.size() * 2);
            
            // Generate odd values: 2 * x - 1
            for (int x : res) {
                if (2 * x - 1 <= n) {
                    next.push_back(2 * x - 1);
                }
            }
            
            // Generate even values: 2 * x
            for (int x : res) {
                if (2 * x <= n) {
                    next.push_back(2 * x);
                }
            }
            
            res = std::move(next);
        }
        
        return res;
    }
};