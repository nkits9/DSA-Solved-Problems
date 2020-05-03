void topo(vector<bool> &vis, vector<int> adj[], int x, stack<int> &s) {
    vis[x] = true;
    for(int i=0; i<adj[x].size(); i++) {
        if(!vis[adj[x][i]])
            topo(vis, adj, adj[x][i], s);
    }
    s.push(x);
}

int* topoSort(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    stack<int> s;
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            topo(vis, adj, i, s);
        }
    }
    int arr[V];
    int i=0;
    while(!s.empty()) {
        arr[i] = s.top();
        s.pop();
        i++;
    }
    int *A = arr;
    return A;
}