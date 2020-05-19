#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int> pii;

int minDiceThrows(int &n, int *moves, bool *vis) {
    queue<pii> q;
    q.push({1, 0});
    vis[1] = true;
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        if(a == n-1)  return b;  
        q.pop();
        for(int i=a+1; i<=a+6 && i<n; i++) {
            if(!vis[i])
                if(moves[i] == -1)
                    q.push({i, b+1});
                else
                    q.push({moves[i], b+1});
                vis[i] = true;
        }
    }
    return -1;
}

int main() {
	IOS;
	int t, e, a, b;
	cin >> t;
	while(t--) {
	    int n = 31;
	    int moves[n]; 
	    bool vis[n];
	    memset(vis, false, sizeof(vis));
	    memset(moves,-1,sizeof moves);
	    cin >> e;
	    while(e--) {
	        cin >> a >> b;
	        moves[a] = b;
	    }
	    cout << minDiceThrows(n, moves, vis) << endl; 
	}
}