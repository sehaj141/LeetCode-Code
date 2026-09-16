class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = pattern.size();
        
        // Build combined array: pattern + sentinel (2) + diff(nums)
        vector<int> combined = pattern;
        combined.push_back(2); // Delimiter not in {-1, 0, 1}

        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (nums[i + 1] > nums[i]) combined.push_back(1);
            else if (nums[i + 1] == nums[i]) combined.push_back(0);
            else combined.push_back(-1);
        }

        int total_len = combined.size();
        vector<int> z(total_len, 0);
        int l = 0, r = 0;

        for (int i = 1; i < total_len; ++i) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < total_len && combined[z[i]] == combined[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        int count = 0;
        // Check occurrences in the diff section (starts after pattern and sentinel)
        for (int i = m + 1; i < total_len; ++i) {
            if (z[i] == m) {
                count++;
            }
        }

        return count;
    }
};