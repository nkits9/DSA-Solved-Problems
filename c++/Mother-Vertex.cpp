void dfsUtil(int u, vector<bool> &visited, vector<int> adj[]) {
	visited[u] = true; 
	
	for (auto v : adj[u]) 
		if (!visited[v]) 
			dfsUtil(v, visited, adj);
}

int findMother(int V, vector<int> adj[]) { 
	vector <bool> visited(V, false);

	int v = 0; 
    // track the last visited vertex.
	for (int i = 0; i < V; i++) { 
		if (visited[i] == false) { 
			dfsUtil(i, visited, adj); 
			v = i; 
		} 
	} 

	fill(visited.begin(), visited.end(), false); 
	// starting from vertex v visit the whole graph 
	dfsUtil(v, visited, adj); 
	// if any vertex is unvisited then the node v is not mother vertex 
	// so on mother vertex is present
	for (int i=0; i<V; i++)
		if (visited[i] == false) 
			return -1; 

	return v; 
}