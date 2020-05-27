int minVertex(int weight[], bool vis[], int V) {
    int min = INT_MAX, idx;
    for(int i=0; i<V; i++) {
        if(!vis[i] && min > weight[i]) {
            idx = i;
            min = weight[i];
        }
    }
    return idx;
}

int spanningTree(int V, int E, vector<vector<int> > edge) {
    int totalWt=0;
    bool vis[V];
    int weight[V];
    for(int i=0; i<V; i++) {
        weight[i]=INT_MAX, vis[i]=false;
    }
    weight[0] = 0;   
    for(int i=0; i<V; i++) {
        int u = minVertex(weight, vis, V);
        vis[u] = true;
        totalWt += weight[u];
        for(int v=0; v<V; v++) {
            if(edge[u][v]!=INT_MAX && !vis[v] && weight[v]>edge[u][v]) {
                    weight[v] = edge[u][v];
            }
        }
    }
    return totalWt;
}