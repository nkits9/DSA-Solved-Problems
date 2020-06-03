#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define pii pair<int, int>


void DFS(int s, vector<pii> &v, vector<bool> &vis, int &end, int &dia) {
    vis[s] = true;
    end = s;
    dia = min(v[s].second, dia);
    if(v[s].first != -1 && !vis[v[s].first]) {
        DFS(v[s].first, v, vis, end, dia);
    }
}

int main() {
	IOS;
	int t, n, p, a, b, d;
	cin >> t;
	while(t--) {
	    cin >> n >> p;
	    
	    unordered_map<int, bool> start;
	    for(int i=1; i<n+1; i++)    start[i] = true;
	    
	    vector<pii> v(n+1, mp(-1, INT_MAX));

		while(p--) {
	        cin >> a >> b >> d;
	        v[a].first = b;
	        v[a].second = d;
	        start[b] = false; // Mark false if it has parent.
	    }

	    int ans = 0;
	    vector<int> res;  
	    vector<bool> vis(n+1, false);
	    for(int i=1; i<n+1; i++) {
	        if(!vis[i] && start[i] && v[i].first != -1) {
	            d = INT_MAX;
	            DFS(i, v, vis, b, d);
	            ans++;
	            res.pb(i), res.pb(b), res.pb(d);
	        }
	    }

	    cout << ans << endl;
	    for(int i=0; i<res.size(); i=i+3){
	    	cout << res[i] << " ";
	    	cout << res[i+1] << " ";
	    	cout << res[i+2] << endl;
	    }
	}
}