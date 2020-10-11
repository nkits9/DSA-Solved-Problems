typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:    
    bool isEqual(vi &nums, int n, int target, vvi &dp) {
        if(n<0 || target<0)   return false;
        if(target==0)   return true;
        if(dp[n][target] != -1)  return dp[n][target];
        
        bool result = isEqual(nums, n-1, target-nums[n], dp) || isEqual(nums, n-1, target, dp);
        dp[n][target] = result;
        
        return dp[n][target]==1 ? true : false;
    }
    
    bool canPartition(vi &nums) {
        int sum=0, n = nums.size();
        for(int i=0; i<n; i++)
            sum += nums[i];
        
        if(sum%2!=0)    return false;
        
        int target = sum/2;
        vvi dp(n, vi(target+1, -1));

        return isEqual(nums, n-1, target, dp); 
    }
};