bool DFSUtil(int s, vector<int> *adj, bool *vis, int parent) {
    vis[s] = true;
    for(int i=0; i<adj[s].size(); i++) {
        if(!vis[adj[s][i]]) {
            if(DFSUtil(adj[s][i], adj, vis, s))
                return true;
        }
        else if(adj[s][i] != parent) {
             return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V) {
    bool vis[V] = {false};
    for(int i=0; i<V; i++) {
        if(!vis[i])
            if(DFSUtil(i, adj, vis, -1))
                return true;
    }
    return false;
}