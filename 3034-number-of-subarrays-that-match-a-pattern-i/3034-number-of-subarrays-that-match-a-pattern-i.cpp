class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        // Step 1: Transform nums into directional differences
        vector<int> diff(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] > nums[i]) diff[i] = 1;
            else if (nums[i + 1] == nums[i]) diff[i] = 0;
            else diff[i] = -1;
        }

        // Step 2: Build KMP prefix function (pi table) for pattern
        vector<int> pi(m, 0);
        for (int i = 1; i < m; ++i) {
            int j = pi[i - 1];
            while (j > 0 && pattern[i] != pattern[j]) {
                j = pi[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                j++;
            }
            pi[i] = j;
        }

        // Step 3: Run KMP search over diff
        int matches = 0;
        int j = 0; // Length of current prefix match
        for (int i = 0; i < diff.size(); ++i) {
            while (j > 0 && diff[i] != pattern[j]) {
                j = pi[j - 1];
            }
            if (diff[i] == pattern[j]) {
                j++;
            }
            if (j == m) {
                matches++;
                j = pi[j - 1]; // Look for next possible match
            }
        }

        return matches;
    }
};