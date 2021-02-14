class Solution {
public:
    
   int LongestPalinSubseq(int l, int r, string &s, vector<vector<int>> &dp) {
        if(dp[l][r])    return dp[l][r];

        if(l >= r) {
            dp[l][r] = (l==r) ? 1 : 0;
            return dp[l][r];
        }

        if(s[l]==s[r]) {
            dp[l][r] = LongestPalinSubseq(l+1, r-1, s, dp) + 2;
        }
        else if(s[l] != s[r]) {
            dp[l][r] = max(LongestPalinSubseq(l+1, r, s, dp), LongestPalinSubseq(l, r-1, s, dp));
        }

        return dp[l][r];
    } 

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        return n - LongestPalinSubseq(0, n-1, s, dp);   
    }

};