typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    
    int longestCommonSubsequence(string a, string b, vvi &dp) {
        int n = a.size(), m = b.size();        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) { 
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
    
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size(), m = b.size();        
        vvi dp(n+1, vi(m+1, 0));

        int lengthOfLCS = longestCommonSubsequence(a, b, dp);

        // [Imp] =>  Length of SCS = n + m - lengthOfLCS

        int i=n, j=m;
        string res = "";

        while(i>0 && j>0) {
            if(a[i-1] == b[j-1]) {
                res += a[i-1];
                i--; j--;
            }
            else if(dp[i][j-1] > dp[i-1][j]) {
                res += b[j-1];
                j--;
            }
            else {
                res += a[i-1];
                i--;
            }
        } 

        while(i>0) {
          res += a[i-1];
          i--;
        }
        while(j>0) {
            res += b[j-1];
            j--;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};