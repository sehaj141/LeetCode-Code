// Helper class to store DP results
struct DpAns {
    long long score;            // Maximum score for this state
    vector<int> list;           // Indices of selected intervals

    DpAns(long long score = 0, vector<int> list = {}) : score(score), list(list) {}
};

// Helper class to store intervals with their indices
struct Pair {
    int idx;                    // Index of the interval in the input
    vector<int> interval;       // The interval details [li, ri, weighti]

    Pair(int idx, vector<int> interval) : idx(idx), interval(interval) {}

    // Sort pairs by their start point (li)
    bool operator<(const Pair& p) const {
        return interval[0] < p.interval[0];
    }
};

class Solution {
    unordered_map<string, DpAns> memo; // Memoization map to store the result of states (i, k)

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Pair> dintervals;

        // Create a list of Pair objects to store intervals along with their indices
        for (int i = 0; i < n; ++i) {
            dintervals.emplace_back(i, intervals[i]);
        }

        // Sort intervals based on their start points (li)
        sort(dintervals.begin(), dintervals.end());

        // Find the best solution with at most 4 intervals
        DpAns result = solve(dintervals, 0, 4);

        // Convert the result list to a vector for the final output
        return result.list;
    }

private:
    // Recursive function to find the best solution for picking intervals
    DpAns solve(vector<Pair>& intervals, int i, int k) {
        if (k == 0 || i >= intervals.size()) {
            return DpAns(0, {});
        }

        // Generate a unique key for the current state (i, k)
        string key = to_string(i) + "*" + to_string(k);

        // If this state has already been computed, return the cached result
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Choice 1: Skip the current interval
        DpAns ans1 = solve(intervals, i + 1, k);

        // Choice 2: Take the current interval
        int nextIdx = findNextIndex(intervals, intervals[i].interval[1], i + 1, intervals.size() - 1);
        DpAns ans2 = solve(intervals, nextIdx, k - 1);

        // Combine current interval's weight and indices with the solution of the rest
        DpAns ans;
        if (intervals[i].interval[2] + ans2.score > ans1.score) {
            long long score = intervals[i].interval[2] + ans2.score;
            vector<int> list = ans2.list;
            list.push_back(intervals[i].idx);
            sort(list.begin(), list.end());
            ans = DpAns(score, list);
        } else if (intervals[i].interval[2] + ans2.score < ans1.score) {
            ans = ans1;
        } else {
            long long score = ans1.score;
            vector<int> list1 = ans1.list;
            vector<int> list2 = ans2.list;
            list2.push_back(intervals[i].idx);
            sort(list2.begin(), list2.end());
            ans = DpAns(score, lexiSmallerList(list1, list2));
        }

        // Cache the result for the current state
        memo[key] = ans;
        return ans;
    }

    // Binary search to find the next non-overlapping interval
    int findNextIndex(vector<Pair>& intervals, int val, int l, int r) {
        int ans = r + 1; // Default to out-of-bounds if no valid interval found
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid].interval[0] > val) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    // Compare two lists lexicographically
    vector<int> lexiSmallerList(vector<int>& list1, vector<int>& list2) {
        int n1 = list1.size(), n2 = list2.size();
        for (int i = 0; i < min(n1, n2); ++i) {
            if (list1[i] < list2[i]) return list1;
            if (list1[i] > list2[i]) return list2;
        }
        return n1 <= n2 ? list1 : list2;
    }
};