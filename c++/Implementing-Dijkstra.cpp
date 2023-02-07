vector<int> dijkstra(int V, vector<vector<int>> adj[], int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]) {
            int adjNode = it[0];
            int edgeWeight = it[1];

            if(currDist + edgeWeight < dist[adjNode]) {
                dist[adjNode] = currDist + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}
