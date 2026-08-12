#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minCharacters(std::string a, std::string b) {
        int m = a.length(), n = b.length();
        std::vector<int> countA(26, 0), countB(26, 0);
        
        for (char c : a) countA[c - 'a']++;
        for (char c : b) countB[c - 'a']++;

        // Condition 3: Make both strings consist of only one distinct letter
        int max_freq = 0;
        for (int i = 0; i < 26; ++i) {
            max_freq = std::max(max_freq, countA[i] + countB[i]);
        }
        int ans = m + n - max_freq;

        // Conditions 1 & 2: 
        // Condition 1: All characters in 'a' are strictly less than char 'i' ('a' + i), 
        //              and all characters in 'b' are greater than or equal to 'i'.
        // Condition 2: All characters in 'b' are strictly less than char 'i' ('a' + i), 
        //              and all characters in 'a' are greater than or equal to 'i'.
        int sumA = 0, sumB = 0;
        for (int i = 0; i < 25; ++i) { // Split character 'i' goes from 0 ('a') to 24 ('y')
            sumA += countA[i];
            sumB += countB[i];

            // Operations to make all chars in 'a' < ('a' + i + 1) and 'b' >= ('a' + i + 1)
            int cond1 = (m - sumA) + sumB;

            // Operations to make all chars in 'b' < ('a' + i + 1) and 'a' >= ('a' + i + 1)
            int cond2 = (n - sumB) + sumA;

            ans = std::min({ans, cond1, cond2});
        }

        return ans;
    }
};