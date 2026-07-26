class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        
        for (int i = 0; i < difficulty.size(); i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int ans = 0;
        int best = 0;
        int j = 0;

        for (int w : worker) {
            while (j < jobs.size() && jobs[j].first <= w) {
                best = max(best, jobs[j].second);
                j++;
            }

            ans += best;
        }

        return ans;
    }
};