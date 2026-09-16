class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        
        // Compute Z-array
        // z[i] is the length of the longest common prefix between word and word[i..]
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && word[z[i]] == word[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        // Check each step t = 1, 2, ...
        for (int i = k; i < n; i += k) {
            if (z[i] == n - i) {
                return i / k;
            }
        }

        // If no suffix matches, remove all original characters
        return (n + k - 1) / k;
    }
};