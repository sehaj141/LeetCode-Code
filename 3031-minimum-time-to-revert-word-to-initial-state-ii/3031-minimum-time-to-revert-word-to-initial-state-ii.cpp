class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> pi(n, 0);

        // Build KMP prefix table
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && word[i] != word[j]) {
                j = pi[j - 1];
            }
            if (word[i] == word[j]) {
                j++;
            }
            pi[i] = j;
        }

        // Trace all borders from longest to shortest
        vector<bool> is_border(n + 1, false);
        for (int len = pi[n - 1]; len > 0; len = pi[len - 1]) {
            is_border[len] = true;
        }

        // Find the earliest valid step t = 1, 2, ...
        for (int i = k; i < n; i += k) {
            int remaining_len = n - i;
            if (is_border[remaining_len]) {
                return i / k;
            }
        }

        return (n + k - 1) / k;
    }
};