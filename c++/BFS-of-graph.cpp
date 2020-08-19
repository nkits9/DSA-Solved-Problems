vector<int> bfs(vector<int> adj[], int n) {
    vector<int> res;
    bool vis[n] = {false};
    queue<int> q;

    int s = 0;
    q.push(s);
    vis[s] = true;
    
    while(!q.empty()) {
        int t = q.front();
        res.push_back(t);
        q.pop();
        
        for(int v : adj[t]) {
            if(vis[v] == false) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return res;
}
