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
    int createSortedArray(vector<int>& instructions) {
        const int MOD = 1e9 + 7;
        int maxVal = *max_element(instructions.begin(), instructions.end());
        
        FenwickTree bit(maxVal);
        long long totalCost = 0;

        for (int i = 0; i < instructions.size(); ++i) {
            int x = instructions[i];

            // Count strictly less than x: query(x - 1)
            int strictlyLess = bit.query(x - 1);

            // Count strictly greater than x: total elements inserted so far (i) - query(x)
            int strictlyGreater = i - bit.query(x);

            totalCost = (totalCost + min(strictlyLess, strictlyGreater)) % MOD;

            // Insert the current element into the Fenwick tree
            bit.add(x, 1);
        }

        return totalCost;
    }
};