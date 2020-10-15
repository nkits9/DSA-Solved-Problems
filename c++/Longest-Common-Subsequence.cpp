#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"


int dp[101][101];

int LCS(string &s1, string &s2, int i, int j) {
    if(i>=s1.size() || j>=s2.size()) 
        return 0;
        
    if(dp[i][j] != -1)
        return dp[i][j];
        
    else if(s1[i]==s2[j]) 
        dp[i][j] =  1 + LCS(s1, s2, i+1, j+1);
        
    else 
        dp[i][j] =  max(LCS(s1, s2, i+1, j), LCS(s1, s2, i, j+1));
        
    return dp[i][j];
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dp[i][j] = -1;
            }
        }
        
        cout << LCS(s1, s2, 0, 0) << endl;
	}
}