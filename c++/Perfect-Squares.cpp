// Method 1: Top-down

class Solution {
public:
    
    int numOfSquares(int n, vector<int> &dp) {
        if(n == 0)    return dp[0];

        if(n < 0)     return INT_MAX;

        if(dp[n] != -1)     return dp[n];

        int i = 1, ans = INT_MAX;

        while(i*i <= n) {
            ans = min(numOfSquares(n-i*i, dp)+1, ans);
            i++;
        }

        dp[n] = ans;
        return dp[n];
    }


    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        return numOfSquares(n, dp);
    }
    
};



// Method 2: Bottom-up

class Solution {
public:
    
    int numSquares(int n) {
        int dp[n+1], val;
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++) {
            val = INT_MAX;
            for(int j=1; j<=sqrt(i); j++) {
                val = min(dp[i-j*j] + 1, val);
            }
            dp[i] = val;
        }
        
        return dp[n];
    }
    
};