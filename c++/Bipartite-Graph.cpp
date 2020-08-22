bool isBipartite(int edge[][MAX], int V) {
    
    queue<int> q;
    
    int color[V];
    memset(color, -1, sizeof(color));
    
    color[0] = 1;
    q.push(0);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        // Return false if there is a self-loop  
        if (edge[u][u])   return false;  
        
        for(int v=0; v<V; v++) {
            if(edge[u][v]) {
                if(color[v]==-1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v]==color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}