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
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        // Allocate space for m initial positions + n moves to the front
        int totalSize = n + m;
        FenwickTree bit(totalSize);

        // pos[x] stores the 1-based index of number x in the BIT
        vector<int> pos(m + 1);

        // Initially, numbers 1..m are placed at indices (n + 1) .. (n + m)
        for (int i = 1; i <= m; ++i) {
            pos[i] = n + i;
            bit.add(pos[i], 1);
        }

        vector<int> result;
        result.reserve(n);

        // Next available slot at the front starts at index n and decrements
        int head = n;

        for (int val : queries) {
            int currentPos = pos[val];

            // 0-indexed count of active elements strictly before currentPos
            result.push_back(bit.query(currentPos - 1));

            // Remove val from its current position
            bit.add(currentPos, -1);

            // Move val to the front slot
            pos[val] = head;
            bit.add(head, 1);
            head--;
        }

        return result;
    }
};