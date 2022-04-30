class Solution {
public:
    
    int houseRob(int start, int end, vector<int>& nums) {  
        int dp[end];
        
        dp[start] = nums[start]; 
        dp[start+1] = max(nums[start], nums[start+1]);
        
        for(int i=start+2; i<end; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[end-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)  return 0;
        if(n == 1)  return nums[0];
        if(n == 2)  return max(nums[0], nums[1]);
        
        return max(houseRob(0, n-1, nums), houseRob(1, n, nums));
    }
};
