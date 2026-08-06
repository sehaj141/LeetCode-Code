class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);

        int suffix = 1;
        int prefix = 0;

        while (suffix < n) {
            if (s[suffix] == s[prefix]) {
                prefix++;
                lps[suffix] = prefix;
                suffix++;
            } else {
                if (prefix == 0) {
                    suffix++;
                } else {
                    prefix = lps[prefix - 1];
                }
            }
        }

        return s.substr(0, lps[n - 1]);
    }
};