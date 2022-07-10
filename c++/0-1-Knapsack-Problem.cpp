// Method-1 : Bottom Up Approach
int knapSack(int W, int wt[], int val[], int n) { 
    int dp[n+1][W+1];
    
    for(int i=0; i<=n; i++) {
        
        for(int j=0; j<=W; j++) {
            
            if(i==0||j==0) {
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j) {
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
            
        }
    }
    
    return dp[n][W];
}



/*
-------------------------------------------------------------------------------------------------------------------------------
*/

// Method-2 : Top Down Approach

//Function to return max value that can be put in knapsack of capacity W.
int solve(int W, int wt[], int val[], int n, vector<vector<int>> &dp) {
    if(n==0)    return 0;

    if(dp[n][W] != -1)    return dp[n][W];

    if(W >= wt[n-1]) 
        dp[n][W] = max(val[n-1] + solve(W-wt[n-1], wt, val, n-1, dp), solve(W, wt, val, n-1, dp));
    else 
        dp[n][W] = solve(W, wt, val, n-1, dp);

    return dp[n][W];
}


int knapSack(int W, int wt[], int val[], int n) { 
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    return solve(W, wt, val, n, dp);
}
