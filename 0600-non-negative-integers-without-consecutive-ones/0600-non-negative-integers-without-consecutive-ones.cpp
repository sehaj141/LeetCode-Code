class Solution {
public:
    int findIntegers(int n) {
        // Precompute Fibonacci values
        // F[i] stores the number of valid binary strings of length i
        vector<int> F(32);
        F[0] = 1;
        F[1] = 2;
        for (int i = 2; i < 32; ++i) {
            F[i] = F[i - 1] + F[i - 2];
        }

        int count = 0;
        int prev_bit = 0;

        // Traverse from MSB (30th bit for 32-bit integer) down to LSB (0th bit)
        for (int i = 30; i >= 0; --i) {
            if ((n & (1 << i)) != 0) {
                // If the i-th bit is set, consider choices where i-th bit is 0.
                // The lower i bits can form F[i] valid combinations.
                count += F[i];

                // If previous bit was also 1, we found consecutive 1s in n itself.
                // Any further traversal would exceed or match n with invalid patterns.
                if (prev_bit == 1) {
                    return count;
                }
                prev_bit = 1;
            } else {
                prev_bit = 0;
            }
        }

        // Add 1 to count 'n' itself if 'n' contains no consecutive 1s
        return count + 1;
    }
};