void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s] = true;
    cout << s << " ";
    for(int i=0; i<g[s].size(); i++) {
        if(!vis[g[s][i]]) {
            dfs(g[s][i], g, vis);
        }
    }
}