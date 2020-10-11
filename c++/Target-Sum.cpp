typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int target = 0;
    
    int numOfWays(vi &nums, int n, int sum, vvi &dp){
        if(n < 0)   return (sum==target) ? 1 : 0;
        
        if(dp[n][sum+1000] != INT_MIN)    return dp[n][sum+1000];
        
        dp[n][sum+1000] = numOfWays(nums, n-1, sum+nums[n], dp) +
                          numOfWays(nums, n-1, sum-nums[n], dp);
        
        return dp[n][sum+1000];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size(); target = S;
    
        vvi dp(n, vi(2001, INT_MIN));
        return numOfWays(nums, n-1, 0, dp);
    }
};

