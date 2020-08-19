#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int DFSVisit(vector<int> adj[], int *vis, int s) {
    if(vis[s] != -1)    return vis[s];
    int count = 1;
    for(int v : adj[s]) {
        count = max(count, 1 + DFSVisit(adj, vis, v));
    }
    vis[s] = count; // Mark as Visited
    return vis[s];
}

int main() {
    IOS;
    c_p_c();
    int t; cin >> t;
    while(t--) {
        int n, e;
        cin >> n >> e;
        vector<int> adj[n];
        for(int i=0; i<e; i++) {
            int u, v;
            cin >> u >> v; 
            adj[v-1].push_back(u-1);
        }
        
        int vis[n];
        memset(vis, -1, sizeof(vis));

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(vis[i] == -1) {
                ans = max(ans, DFSVisit(adj, vis, i));
            }
        }
        cout << ans << endl;
    }
}