class Solution {
public:
    int LIS(int i, int prevIdx, vector<int> &nums, vector<vector<int>> &dp) {
        if(i == nums.size())  return 0;

        if(dp[i][prevIdx] != -1) {
            return dp[i][prevIdx+1];
        }

        int maximum = INT_MIN;

        if(prevIdx == -1 || nums[i] > nums[prevIdx]) {
            maximum = max(1 + LIS(i+1, i, nums, dp), maximum); 
        }     
        maximum = max(LIS(i+1, prevIdx, nums, dp), maximum);

        dp[i][prevIdx+1] = maximum;

        return dp[i][prevIdx];
    }
q
    int lengthOfLIS(vector<int> &nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return LIS(0, -1, nums, dp);  
    }
};