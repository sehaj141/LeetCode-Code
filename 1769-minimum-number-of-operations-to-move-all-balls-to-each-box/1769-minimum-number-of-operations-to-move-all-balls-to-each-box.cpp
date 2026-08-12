#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        int n = boxes.size();
        std::vector<int> answer(n, 0);

        // Pass 1: Left to Right
        // Accumulate operations needed to move all balls on the left to index i
        int count = 0; // Number of balls seen so far on the left
        int ops = 0;   // Accumulated distance/operations from the left
        for (int i = 0; i < n; ++i) {
            answer[i] += ops;
            count += (boxes[i] - '0');
            ops += count; // Each ball seen so far travels 1 step further
        }

        // Pass 2: Right to Left
        // Accumulate operations needed to move all balls on the right to index i
        count = 0; // Number of balls seen so far on the right
        ops = 0;   // Accumulated distance/operations from the right
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += ops;
            count += (boxes[i] - '0');
            ops += count; // Each ball seen so far travels 1 step further
        }

        return answer;
    }
};