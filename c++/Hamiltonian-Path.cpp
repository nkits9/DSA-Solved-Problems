#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

bool hamiltonianPath(int s, vector<int> adj[], bool *vis, int count) {
	vis[s] = true;
	if(count == 0)  return true;
	
	for(auto v : adj[s]) {
		if(!vis[v]) {
			if(hamiltonianPath(v, adj, vis, count-1))
				return true;
		}
	}
	
	vis[s] = false;
	return false;
}


int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    int n, e, u, v;
	    cin >> n >> e;
	    vector<int> adj[n];
	    for(int i=0; i<e; i++) {
	    	cin >> u >> v;
	    	adj[u-1].push_back(v-1);
	    	adj[v-1].push_back(u-1);
	    }
	    bool vis[n];
	    memset(vis, false, sizeof(vis));
	    int ans = 0;
	    for(int i=0; i<n; i++) {
	    	if(hamiltonianPath(i, adj, vis, n-1)) {
	    		ans = 1;
	    		break;
	    	}
	    }
	    cout << ans << endl;
	}
}


// Exercise : try to print all hamiltonian paths.