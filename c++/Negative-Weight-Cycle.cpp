#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

struct Edge {
    int src, dest, weight;
};

int BellmanFord(int dist[], Edge edge[], int V, int E) {
    for(int i=0; i<V-1; i++) {
        for(int j=0; j<E; j++) {
            if(dist[edge[j].src] + edge[j].weight  < dist[edge[j].dest]) {
                dist[edge[j].dest] = dist[edge[j].src] + edge[j].weight;
            }
        }
    }
    
    for(int j=0; j<E; j++) {
        if(dist[edge[j].src] + edge[j].weight  < dist[edge[j].dest]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    IOS;
    int t; cin >> t;
    while(t--) {
        int V, E;
        cin >> V >> E;
        int dist[V];
        memset(dist, INT_MAX, sizeof(dist));
        dist[0] = 0;
        Edge edge[E];
        int x, y, w;
        for(int i=0; i<E; i++) {
            cin >> x >> y >> w;
            edge[i].src = x;
            edge[i].dest = y;
            edge[i].weight = w;
        }
        cout << BellmanFord(dist, edge, V, E) << endl;
    }
}