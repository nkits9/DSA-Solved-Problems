// Method 1 : Top-down Approach

class Solution {
public:
    
    int houseRob(int i, vector<int>& nums, vector<int>& dp) {
        if(i < 0)   return 0;
        
        if(dp[i]!=-1)   return dp[i];
        
        dp[i] = max(houseRob(i-1, nums, dp), nums[i] + houseRob(i-2, nums, dp));
        
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return houseRob(nums.size()-1, nums, dp);
    }
};


// Method 2 : Bottom-up Approach

class Solution {
public:
    
    int rob(vector<int>& nums) {  
        int n = nums.size();
        
        if(n == 0)  return 0;
        if(n == 1)  return nums[0];
        
        int dp[n];
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
    }
};
