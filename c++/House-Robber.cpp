class Solution {
public:
    
    int houseRob(vector<int> &nums, int k, vector<int> &dp) {
        int n = nums.size();
        if(k>=n)    return 0; 
        
        if(dp[k+2] != -1) {
            return dp[k];
        }
        
        int ans = 0;
        int start = (k>=0) ? nums[k] : 0;
        
        for(int i=k+2; i<n; i++) {
            if(dp[i+2] != -1) {
                ans = max(ans, dp[i+2]);
            else 
                ans = max(ans, houseRob(nums, i, dp)); 
            }
        
        dp[k+2] = start + ans;
        return dp[k+2];
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2, -1);
        return houseRob(nums, -2, dp);
    }
};