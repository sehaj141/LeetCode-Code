#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Custom comparator: frequency descending, then character ascending
    static bool comparator(const pair<int, char>& p1, const pair<int, char>& p2) {
        if (p1.first != p2.first) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }

public:
    string frequencySort(string s) {
        // 1. Count frequencies of all characters safely
        unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }

        // 2. Transfer map entries into a vector for sorting
        vector<pair<int, char>> freqList;
        for (auto& entry : freqMap) {
            freqList.push_back({entry.second, entry.first});
        }

        // 3. Sort using the custom comparator
        sort(freqList.begin(), freqList.end(), comparator);

        // 4. Reconstruct the sorted string
        string ans = "";
        for (const auto& p : freqList) {
            ans.append(p.first, p.second); // Appends character 'p.first' times
        }

        return ans;
    }
};