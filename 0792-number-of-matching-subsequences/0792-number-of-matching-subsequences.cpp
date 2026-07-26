class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> pos[26];

        // Store indices of each character in s
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        int ans = 0;

        for (string &word : words) {
            int prev = -1;
            bool ok = true;

            for (char c : word) {
                auto &indices = pos[c - 'a'];

                auto it = upper_bound(indices.begin(), indices.end(), prev);

                if (it == indices.end()) {
                    ok = false;
                    break;
                }

                prev = *it;
            }

            if (ok) ans++;
        }

        return ans;
    }
};