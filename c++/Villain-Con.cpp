#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int DFSVisit(vector<vector<int>> &adj, vector<int> &vis, int s) {
    if(vis[s] != -1)    return vis[s];
    int count = 1;
    for(int i=0; i<adj[s].size(); i++) {
        count = max(count, 1 + DFSVisit(adj, vis, adj[s][i]));
    }
    vis[s] = count;
    return vis[s];
}


int main() {
    IOS;
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for(int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            adj[v-1].push_back(u-1);
        }
        int maxLen = 0;
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++) {
            if(vis[i] == -1) {
                maxLen = max(maxLen, DFSVisit(adj, vis, i));
            }
        }
        cout << maxLen << endl;
    }
    return 0;
}