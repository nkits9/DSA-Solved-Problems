typedef pair<int, int> pii;

void dijkstra(vector<vector<int>> graph, int src, int V) 
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    bool vis[V]={false};
    pq.push({0, src});
    
    while(!pq.empty()) {
        pii p = pq.top(); pq.pop();
        int u = p.second;
        if(vis[u])  continue;
        vis[u] = true;
        for(int i=0; i < graph[u].size(); i++) {
            int wt = graph[u][i];
            if(dist[u] != INT_MAX && dist[u] + wt < dist[i] && wt != 0) {
                dist[i] = dist[u] + wt;
            }
            pq.push({dist[i], i});
        }
    }
    
    for(int i=0; i<V; i++) {
        cout << dist[i] << " ";
    }
}