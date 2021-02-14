class Solution {
public:
    int maxLenPalin(int l, int r, string &s, vector<vector<int>> &dp) {
        if(dp[l][r])    return dp[l][r];
        
        if(l >= r) {
            dp[l][r] = (l==r) ? 1 : 0;
            return dp[l][r];
        }
        
        if(s[l]==s[r]) {
            dp[l][r] = maxLenPalin(l+1, r-1, s, dp) + 2;
        }
        else if(s[l] != s[r]) {
            dp[l][r] = max(maxLenPalin(l+1, r, s, dp), maxLenPalin(l, r-1, s, dp));
        }
        
        return dp[l][r];
    } 
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        return maxLenPalin(0, n-1, s, dp);   
    }
};