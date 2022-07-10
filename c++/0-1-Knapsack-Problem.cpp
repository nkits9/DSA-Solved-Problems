// Method-1 : Bottom Up Approach
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    IOS;
    // Code starts from here:
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int W; cin>>W;
        int val[n], wt[n];
        for(int i=0;i<n;i++)
            cin>>val[i];
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
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
        cout<<dp[n][W]<<endl;
       // memset(dp,0,sizeof(dp));
        
    }
    return 0;
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
