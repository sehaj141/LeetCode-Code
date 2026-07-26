class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);

        // Count frequency of characters in s
        for (char c : s)
            freq[c - 'a']++;

        string ans;

        // Add characters according to order
        for (char c : order) {
            while (freq[c - 'a'] > 0) {
                ans += c;
                freq[c - 'a']--;
            }
        }

        // Add remaining characters
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                ans += char(i + 'a');
                freq[i]--;
            }
        }

        return ans;
    }
};