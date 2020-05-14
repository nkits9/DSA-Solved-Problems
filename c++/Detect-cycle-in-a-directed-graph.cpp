bool DFSUtil(int s, vector<int> *adj, bool *vis, bool *recStack) {
    vis[s] = true;
    recStack[s] = true;
    for(int i=0; i<adj[s].size(); i++) {
        if(!vis[adj[s][i]]) {
            if(DFSUtil(adj[s][i], adj, vis, recStack))
                return true;
        }
        else if(recStack[adj[s][i]]) {
            return true;
        }
    }
    recStack[s] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    bool vis[V] = {false};
    bool recStack[V] = {false};
    for(int i=0; i<V; i++) {
        if(!vis[i])
            if(DFSUtil(i, adj, vis, recStack))
                return true;
    }
    return false;
}