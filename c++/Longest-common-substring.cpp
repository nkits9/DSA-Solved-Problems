typedef vector<int> vi;
typedef vector<vi> vvi;

int longestCommonSubstr(string s1, string s2, int n, int m) {
    vvi dp(n+1, vi(m+1, -1));
    int lcs = 0;
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                lcs = max(lcs, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return lcs;
}
