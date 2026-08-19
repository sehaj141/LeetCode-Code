class Solution {
    struct FenwickTree {
        int size;
        vector<int> tree;

        FenwickTree(int n) : size(n), tree(n + 1, 0) {}

        void add(int i, int delta) {
            for (; i <= size; i += i & -i) {
                tree[i] += delta;
            }
        }

        int query(int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += tree[i];
            }
            return sum;
        }
    };

public:
    string minInteger(string num, int k) {
        int n = num.size();

        // If k is large enough to perform a full bubble sort, sort the whole string
        if (k >= (long long)n * (n - 1) / 2) {
            sort(num.begin(), num.end());
            return num;
        }

        // Store 1-based original positions for each digit '0' through '9'
        vector<deque<int>> pos(10);
        for (int i = 0; i < n; ++i) {
            pos[num[i] - '0'].push_back(i + 1);
        }

        // Fenwick tree to track how many elements have already been placed (shifted left)
        FenwickTree bit(n);
        string result = "";
        result.reserve(n);

        for (int i = 0; i < n; ++i) {
            // Try to pick the smallest available digit '0'..'9' that is reachable within k swaps
            for (int d = 0; d <= 9; ++d) {
                if (pos[d].empty()) continue;

                int originalIdx = pos[d].front();
                // Number of elements originally before this digit that have already moved past it
                int alreadyShifted = bit.query(originalIdx);
                // Current 0-based index is originalIdx - 1 - alreadyShifted
                int cost = (originalIdx - 1) - alreadyShifted;

                if (cost <= k) {
                    k -= cost;
                    result.push_back('0' + d);
                    bit.add(originalIdx, 1);
                    pos[d].pop_front();
                    break;
                }
            }
        }

        return result;
    }
};