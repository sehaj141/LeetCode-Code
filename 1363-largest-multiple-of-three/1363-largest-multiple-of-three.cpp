class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        // Count frequency of each digit (0-9)
        vector<int> count(10, 0);
        int sum = 0;
        
        for (int d : digits) {
            count[d]++;
            sum += d;
        }

        // Helper lambda to remove 'k' smallest digits matching remainder 'rem'
        auto removeDigits = [&](int rem, int k) {
            for (int d = rem; d < 10 && k > 0; d += 3) {
                while (count[d] > 0 && k > 0) {
                    count[d]--;
                    sum -= d;
                    k--;
                }
            }
            return k == 0; // Returns true if we successfully removed k digits
        };

        // Adjust digits based on remainder
        if (sum % 3 == 1) {
            if (!removeDigits(1, 1)) {
                removeDigits(2, 2);
            }
        } else if (sum % 3 == 2) {
            if (!removeDigits(2, 1)) {
                removeDigits(1, 2);
            }
        }

        // Build the result string in descending order (9 down to 0)
        string result = "";
        for (int d = 9; d >= 0; --d) {
            result.append(count[d], '0' + d);
        }

        // Handle edge case where the result is all zeros (e.g., "000" -> "0")
        if (!result.empty() && result[0] == '0') {
            return "0";
        }

        return result;
    }
};