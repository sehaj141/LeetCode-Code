#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        // Generate valid intervals
        vector<pair<int, int>> intervals; // {end, start} for easy sorting by end time

        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int left = first[i];
            int right = last[i];
            bool valid = true;

            for (int j = left; j <= right; ++j) {
                int c = s[j] - 'a';
                // If a character inside [left, right] started before left,
                // this interval is redundant/invalid because it will be covered by that character's start.
                if (first[c] < left) {
                    valid = false;
                    break;
                }
                right = max(right, last[c]);
            }

            if (valid) {
                intervals.push_back({right, left});
            }
        }

        // Sort intervals by their ending position (greedy interval scheduling)
        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int prev_end = -1;

        for (const auto& [r, l] : intervals) {
            if (l > prev_end) {
                ans.push_back(s.substr(l, r - l + 1));
                prev_end = r;
            }
        }

        return ans;
    }
};