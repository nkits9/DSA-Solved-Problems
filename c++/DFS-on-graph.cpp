void DFSUtil(int i, vector<int> adj[], bool *vis, vector<int> &res) {
    vis[i] = true;
    res.push_back(i);
    
    for(int v : adj[i]) {
        if(!vis[v]) {
            DFSUtil(v, adj, vis, res);
        }
    }
}

vector<int> dfs(vector<int> adj[], int n) {
    vector<int> res;
    bool vis[n];
    memset(vis, false, sizeof(vis));
    
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            DFSUtil(i, adj, vis, res);
        }
    }
    
    return res;
}