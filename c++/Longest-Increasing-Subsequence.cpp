class Solution {
public:
    int LIS(int i, int prevIdx, vector<int> &nums, vector<vector<int>> &dp) {        
        if(i == nums.size())   return 0;

        if(prevIdx != -1 && dp[i][prevIdx] != -1)    return dp[i][prevIdx];
        
        int maximum = INT_MIN;

        if(prevIdx == -1 || nums[i] > nums[prevIdx])
            maximum = max(1 + LIS(i+1, i, nums, dp), LIS(i+1, prevIdx, nums, dp));
        else
            maximum = LIS(i+1, prevIdx, nums, dp);
        
        if(prevIdx != -1) {
            dp[i][prevIdx] = maximum;
        }

        return maximum;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return LIS(0, -1, nums, dp);
    }
};
