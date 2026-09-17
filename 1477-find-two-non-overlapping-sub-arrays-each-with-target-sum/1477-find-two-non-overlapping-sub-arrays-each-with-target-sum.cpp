#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] stores the minimum length of a valid sub-array ending at or before index i
        vector<int> min_len(n, n + 1);
        
        int left = 0;
        int current_sum = 0;
        int ans = n + 1;
        int best_so_far = n + 1;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            // Shrink window from the left if current_sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left++];
            }
            
            // Found a valid sub-array in [left, right]
            if (current_sum == target) {
                int curr_len = right - left + 1;
                
                // If there is a valid sub-array to the left of `left`
                if (left > 0 && min_len[left - 1] <= n) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }
                
                best_so_far = min(best_so_far, curr_len);
            }
            
            // Update prefix minimum length up to index `right`
            min_len[right] = best_so_far;
        }
        
        return ans > n ? -1 : ans;
    }
};