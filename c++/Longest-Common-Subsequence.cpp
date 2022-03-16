typedef vector<int> vi;
typedef vector<vi> vvi;

// Top Down Approach:

class Solution {
public:
    
    int LCS(int n, int m, string &s1, string &s2, vvi &dp) { 
        if(n==0 || m==0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s1[n-1] == s2[m-1])
            dp[n][m] = 1 + LCS(n-1, m-1, s1, s2, dp);
        else
            dp[n][m] = max(LCS(n-1, m, s1, s2, dp), LCS(n, m-1, s1, s2, dp));
        
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vvi dp(n+1, vi(m+1, -1));
        return LCS(n, m, s1, s2, dp);
    }
};


// Bottom up Approach:

class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vvi dp(n+1, vi(m+1, -1));
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                
                if(i==0 || j==0) {
                    dp[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

// Print LCS:

string printLCS(vvi &dp) {
    int i=dp.size(), j=dp[0].size();
    string LCS = "";

    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            LCS += s1[i-1];
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else                
                j--;
        }
    }
    reverse(LCS.begin(), LCS.end());
    return LCS;
}
