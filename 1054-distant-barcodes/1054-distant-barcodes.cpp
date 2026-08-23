#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes) {
        std::unordered_map<int, int> countMap;
        for (int code : barcodes) {
            countMap[code]++;
        }
        
        // Convert to a vector of pairs: {frequency, value}
        std::vector<std::pair<int, int>> freqList;
        for (auto& [val, count] : countMap) {
            freqList.push_back({count, val});
        }
        
        // Sort descending by frequency
        std::sort(freqList.begin(), freqList.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        
        int n = barcodes.size();
        std::vector<int> result(n);
        int idx = 0;
        
        for (auto& [count, val] : freqList) {
            for (int i = 0; i < count; ++i) {
                if (idx >= n) {
                    idx = 1; // Wrap around to odd indices
                }
                result[idx] = val;
                idx += 2;
            }
        }
        
        return result;
    }
};