#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

int BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    
    for(int i=0; i<V; i++) 
        dist[i] = INT_MAX;
    dist[src] = 0;
    
    for(int i=0; i<V-1; i++) {
        for(int j=0; j<E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight;
        }
    }
    
    for(int i=0; i<E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
            return 1;
    }
    return 0;
}


int main() {
    IOS;
    int t; cin >> t;
    while(t--) {
        int V, E;
        cin >> V >> E;
        struct Graph* graph = createGraph(V, E);
        for(int i=0; i<E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph->edge[i].src = u;
            graph->edge[i].dest = v;
            graph->edge[i].weight = w;
        }
        cout << BellmanFord(graph, 0) << endl;
    }
	return 0;
}