void dfs(int i, vector<int> adj[], vector<bool> &vis, vector<int> &res) {
    res.push_back(i);

    for(int v : adj[i]) {
        if(!vis[v]) {
            vis[v] = true;
            dfs(v, adj, vis, res);
        }
    }
}


vector<int>dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    vector<int> res;

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            vis[i] = true;
            dfs(i, adj, vis, res);
        }
    }
    
    return res;
}
