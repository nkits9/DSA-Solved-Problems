// Method 1 : Bottom-up Approach

class Solution {
public:
    
    int rob(vector<int>& nums) {  
        int n = nums.size();
        
        if(n == 0)  return 0;
        if(n == 1)  return nums[0];
        if(n == 2)  return max(nums[0], nums[1]);
        
        int dp[n];
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
    }
};




// Method 2 : Top-down Approach

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