void tSort(int x, vector<int> adj[], bool *vis, stack<int> &s) {
    vis[x] = true;
    for(int v : adj[x]) {
        if(!vis[v]) {
            tSort(v, adj, vis, s);
        }
    }
    s.push(x);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int> s;
    bool vis[V] = {false};
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            tSort(i, adj, vis, s);
        }
    }
    vector<int> res;
    while(!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

