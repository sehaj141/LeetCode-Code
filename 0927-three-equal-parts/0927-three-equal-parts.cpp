#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> threeEqualParts(std::vector<int>& arr) {
        int totalOnes = 0;
        for (int bit : arr) {
            totalOnes += bit;
        }

        // If there are no 1s, any valid partition works
        if (totalOnes == 0) {
            return {0, 2};
        }

        // Total number of 1s must be divisible by 3
        if (totalOnes % 3 != 0) {
            return {-1, -1};
        }

        int targetOnes = totalOnes / 3;
        int first = -1, second = -1, third = -1;
        int count = 0;

        // Find starting index of the 1st, 2nd, and 3rd parts
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 1) {
                count++;
                if (count == 1) first = i;
                else if (count == targetOnes + 1) second = i;
                else if (count == 2 * targetOnes + 1) third = i;
            }
        }

        // Match all three intervals element by element until the end of the array
        int n = arr.size();
        while (third < n) {
            if (arr[first] != arr[second] || arr[first] != arr[third]) {
                return {-1, -1};
            }
            first++;
            second++;
            third++;
        }

        // first - 1 is the end of the 1st partition (i)
        // second is the start of the 3rd partition (j = second)
        return {first - 1, second};
    }
};