#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int numSpecialEquivGroups(std::vector<string>& words) {
        std::unordered_set<std::string> unique_groups;

        for (const std::string& word : words) {
            std::string even = "";
            std::string odd = "";

            // Separate characters at even and odd indices
            for (int i = 0; i < word.length(); ++i) {
                if (i % 2 == 0) {
                    even += word[i];
                } else {
                    odd += word[i];
                }
            }

            // Sort both strings to get canonical ordering
            std::sort(even.begin(), even.end());
            std::sort(odd.begin(), odd.end());

            // Combine into a single unique key
            std::string key = even + "#" + odd;
            unique_groups.insert(key);
        }

        return unique_groups.size();
    }
};