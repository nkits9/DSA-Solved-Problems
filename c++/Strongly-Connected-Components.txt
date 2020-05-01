void transpose(int V, vector<int> adj[], vector<int> transpose_adj[])
{
    for(int u=0;u<V;u++)
        for(auto v : adj[u])
            transpose_adj[v].push_back(u);
}

stack<int> s;

int dfs(vector<int> adj[], bool *visited, int u)
{
    visited[u]=true;
    for(auto v : adj[u])
    {
        if(visited[v]==0)
            dfs(adj, visited, v);
    }
}

int fillorder(vector<int> adj[], bool* visited, int u)
{
    visited[u]=true;
    for(auto v : adj[u])
        if(visited[v]==0)
            fillorder(adj, visited,v);
    s.push(u);
}

int kosaraju(int V, vector<int> adj[])
{
    bool visited[V] = {0};
    for(int i=0;i<V;i++)
        if(visited[i]==false)
            fillorder(adj, visited, i);
    
    vector<int> transpose_adj[V];
    transpose(V, adj, transpose_adj);
  
    for(int i = 0; i<V; i++)
       visited[i] = false;

    int ans=0;
    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
       
        if(!visited[temp])
        {
            dfs(transpose_adj, visited, temp);
            ans++;
        } 
    }
    
    return ans;
 }