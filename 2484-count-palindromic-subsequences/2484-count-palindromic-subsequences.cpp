class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<vector<long long>> leftPair(10, vector<long long>(10, 0));
        vector<vector<long long>> rightPair(10, vector<long long>(10, 0));

        vector<long long> leftCnt(10, 0), rightCnt(10, 0);

        // Build rightPair
        for (char ch : s)
            rightCnt[ch - '0']++;

        fill(rightCnt.begin(), rightCnt.end(), 0);

        for (int i = n - 1; i >= 0; i--) {
            int x = s[i] - '0';

            for (int j = 0; j < 10; j++)
                rightPair[x][j] += rightCnt[j];

            rightCnt[x]++;
        }

        long long ans = 0;

        fill(rightCnt.begin(), rightCnt.end(), 0);

        for (int i = n - 1; i >= 0; i--)
            rightCnt[s[i] - '0']++;

        for (int mid = 0; mid < n; mid++) {

            int x = s[mid] - '0';

            rightCnt[x]--;

            for (int j = 0; j < 10; j++)
                rightPair[x][j] -= rightCnt[j];

            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ans = (ans + leftPair[a][b] * rightPair[b][a]) % MOD;
                }
            }

            for (int j = 0; j < 10; j++)
                leftPair[j][x] += leftCnt[j];

            leftCnt[x]++;
        }

        return ans;
    }
};