#include <string>
#include <vector>

class Solution {
public:
    int uniqueLetterString(std::string s) {
        int n = s.length();
        // Store indices of each character's occurrences
        // Initialize with -1 to represent the boundary before index 0
        std::vector<std::vector<int>> pos(26, std::vector<int>{-1});

        for (int i = 0; i < n; ++i) {
            pos[s[i] - 'A'].push_back(i);
        }

        long long totalUnique = 0;

        for (int c = 0; c < 26; ++c) {
            // Append n to represent the boundary after index n - 1
            pos[c].push_back(n);

            // Calculate contribution of each occurrence pos[c][k]
            for (int k = 1; k < (int)pos[c].size() - 1; ++k) {
                int prev = pos[c][k - 1];
                int curr = pos[c][k];
                int next = pos[c][k + 1];

                totalUnique += (long long)(curr - prev) * (next - curr);
            }
        }

        return totalUnique;
    }
};