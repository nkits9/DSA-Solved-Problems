class Solution {
public:
    
    int minimum(int a, int b, int c) {
        return a<b ? min(a, c) : min(b, c);
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        int maxArea = 0;
        int dp[n][m];
        
        for(int i=0; i<n; i++) {
            dp[i][0] = mat[i][0] - '0';
            maxArea = max(dp[i][0], maxArea);
        }
        
        for(int j=0; j<m; j++) {
            dp[0][j] = mat[0][j] - '0';
            maxArea = max(dp[0][j], maxArea);
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(mat[i][j]-'0'==1) {
                    dp[i][j] = minimum(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
                    maxArea = max(dp[i][j], maxArea);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxArea*maxArea;
    }
};