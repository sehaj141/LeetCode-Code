class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Frequency array for range [0, 100]
        vector<int> count(102, 0);
        
        // Count frequencies of each number
        for (int num : nums) {
            count[num]++;
        }
        
        // Compute prefix sums: count[i] will store total elements <= i
        for (int i = 1; i <= 100; ++i) {
            count[i] += count[i - 1];
        }
        
        // Map original array values to their counts of strictly smaller elements
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                result[i] = count[nums[i] - 1];
            }
        }
        
        return result;
    }
};