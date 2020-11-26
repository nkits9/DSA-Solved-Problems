class Solution {
public:
    int minCoins(vector<int> &coins, vector<int> &dp, int rem) {
        if(rem == 0)  return 0;
        
        if(rem < 0)  return INT_MAX;
        
        if(dp[rem] != -1)   return dp[rem];
        
        int min = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            int numOfCoins = minCoins(coins, dp, rem-coins[i]);
            if(numOfCoins < INT_MAX) {
                min = std::min(min, numOfCoins+1);
            }
        }
        
        dp[rem] = (dp[rem] == -1) ? min : std::min(dp[rem], min);
        
        return dp[rem];       
    }
    
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount+1, -1);
        int result = minCoins(coins, dp, amount);
        return result==INT_MAX ? -1 : result;
    }
};