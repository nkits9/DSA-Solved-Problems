class Solution {
public:
    int houseRob(int start, int n, vector<int> &nums) {
        int dp[n];
        
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start + 0], nums[start + 1]);
        
        for(int i=start+2; i<n; i++) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];
        if(n==2)    return  max(nums[0], nums[1]);
        
        return max(houseRob(0, n-1, nums), houseRob(1, n, nums));
    }
};