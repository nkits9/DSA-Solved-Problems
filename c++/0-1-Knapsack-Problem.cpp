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
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;

int knapsack(int val[], int wt[], int W, int i, int** dp) {
    if(i<0)     return 0;
    if(dp[i][W] != -1)    return dp[i][W];
    
    if(W >= wt[i]) {
        dp[i][W] = max(val[i] + knapsack(val, wt, W-wt[i], i-1, dp),
                        knapsack(val, wt, W, i-1, dp));
    } else {
        dp[i][W] = knapsack(val, wt, W, i-1, dp);
    }
    
    return dp[i][W];
}


int main() { 
    IOS;
    // Code starts from here:
    int t; cin >> t;
    while(t--) {
        int n, W; 
        cin >> n >> W;
        int val[n], wt[n];
        for(int i=0; i<n; i++) 
            cin >> val[i];
        for(int i=0; i<n; i++) 
            cin >> wt[i];
            
        int** dp; 
        dp = new int*[n]; 
  
        for (int i = 0; i < n; i++) 
            dp[i] = new int[W + 1]; 
  
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < W + 1; j++) 
                dp[i][j] = -1; 

        cout << knapsack(val, wt, W, n-1, dp) << endl; 
    } 
} 