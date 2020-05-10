void bfs(int s, vector<int> adj[], bool vis[], int N) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()) {
        int t = q.front();
        cout << t << " ";
        q.pop();
        for(int i=0; i<adj[t].size(); i++) {
            if(!vis[adj[t][i]]) {
                q.push(adj[t][i]);
                vis[adj[t][i]] = true;
            }
        }
    }
}