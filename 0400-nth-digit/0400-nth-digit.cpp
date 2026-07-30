class Solution {
public:
    int findNthDigit(int n) {
        long long digit = 1;
        long long count = 9;
        long long start = 1;

        // Skip complete groups
        while (n > digit * count) {
            n -= digit * count;
            digit++;
            count *= 10;
            start *= 10;
        }

        // Find the actual number
        long long number = start + (n - 1) / digit;

        // Convert to string
        string s = to_string(number);

        // Return the required digit
        return s[(n - 1) % digit] - '0';
    }
};