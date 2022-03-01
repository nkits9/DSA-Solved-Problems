typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:    
    bool isEqual(vi &nums, int n, int sum, vvi &dp) {
        
        if(sum==0)   return true;
        
        if(n==0 && sum!=0)   return false;
        
        if(dp[n][sum] != -1)    return dp[n][sum];
        
        if(sum >= nums[n-1]) {
            dp[n][sum] = isEqual(nums, n-1, sum - nums[n-1], dp) || isEqual(nums, n-1, sum, dp);
        }
        else {
            dp[n][sum] = isEqual(nums, n-1, sum, dp);
        }
        
        return dp[n][sum];
    }
    
    bool canPartition(vi &nums) {
        int totalSum=0, n = nums.size();
        for(int i=0; i<n; i++)
            totalSum += nums[i];
        
        if(totalSum % 2 != 0)    return false;
        
        int sum = totalSum / 2;
        vvi dp(n+1, vi(sum+1, -1));

        return isEqual(nums, n, sum, dp); 
    }
};
