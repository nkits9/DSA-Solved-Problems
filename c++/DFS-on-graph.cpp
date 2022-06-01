void dfs(int i, vector<int> adj[], vector<bool> &vis, vector<int> &res) {
    vis[i] = true;
    res.push_back(i);

    for(int v : adj[i]) {
        if(!vis[v]) {
            dfs(v, adj, vis, res);
        }
    }
}


vector<int>dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    vector<int> res;

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, res);
        }
    }
    
    return res;
}
