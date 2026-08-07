#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        // Step 1: Sort nums1
        sort(nums1.begin(), nums1.end());
        
        // Step 2: Store indices of nums2 and sort them based on nums2 values in descending order
        vector<int> ids(n);
        for (int i = 0; i < n; ++i) {
            ids[i] = i;
        }
        sort(ids.begin(), ids.end(), [&](int a, int b) {
            return nums2[a] > nums2[b];
        });
        
        // Step 3: Two pointers for nums1
        int left = 0;         // Smallest available element in nums1
        int right = n - 1;    // Largest available element in nums1
        
        vector<int> result(n);
        
        // Match elements starting from the largest in nums2
        for (int i = 0; i < n; ++i) {
            int idx = ids[i];
            
            if (nums1[right] > nums2[idx]) {
                // We can win this position using our largest available element
                result[idx] = nums1[right];
                right--;
            } else {
                // We cannot beat nums2[idx], so waste our smallest available element here
                result[idx] = nums1[left];
                left++;
            }
        }
        
        return result;
    }
};