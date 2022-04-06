// Method 1: 

// 1. Top down appproach: 

class Solution {
public:
    int maxLenPalin(int l, int r, string &s, vector<vector<int>> &dp) {
        if(l >= r)   
            return (l==r) ? 1 : 0;
        
        else if(dp[l][r]) 
            return dp[l][r];
        
        else if(s[l]==s[r]) 
            dp[l][r] = maxLenPalin(l+1, r-1, s, dp) + 2;
        
        else if(s[l] != s[r]) 
            dp[l][r] = max(maxLenPalin(l+1, r, s, dp), maxLenPalin(l, r-1, s, dp));
        
        return dp[l][r];
    } 
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        return maxLenPalin(0, n-1, s, dp);   
    }
};


// 2. Bottom up appproach: 

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n-1; i>=0; i--) {
        dp[i][i] = 1;
        for (int j = i+1; j<n; j++) {
            if (s[i] == s[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}

// Method 2: Using LCS 

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
        
                if(i==0 || j==0) 
                    dp[i][j] = 0;
                
                else if(s1[i-1] == s2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        return longestCommonSubsequence(s1, s2);
    }
};

