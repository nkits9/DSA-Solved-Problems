void DFSUtil(int s, vector<int> *adj, bool &iscyclic, bool *vis, bool *recStack) {
    vis[s] = true;
    recStack[s] = true;
    for(int i=0; i<adj[s].size(); i++) {
        if(!vis[adj[s][i]]) {
            DFSUtil(adj[s][i], adj, iscyclic, vis, recStack);
        }
        else if(recStack[adj[s][i]]) {
            iscyclic = true; return;
        }
    }
    recStack[s] = false;
    return;
}

bool isCyclic(int V, vector<int> adj[]) {
    bool iscyclic = false;
    bool vis[V] = {false};
    bool recStack[V] = {false};
    for(int i=0; i<V; i++) {
        if(!vis[i])
            DFSUtil(i, adj, iscyclic, vis, recStack);
    }
    return iscyclic;
}