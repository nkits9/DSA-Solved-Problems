#include <bits/stdc++.h>
using namespace std;

void printAdj(vector<int> adj[], int v) {
    for(int i=0; i<v; i++) {
        cout<<i;
        for(int j=0; j<adj[i].size(); j++) {
            cout<<"-> "<<adj[i][j];
        }
        cout<<"\n";
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	while(t--) {
	    int v, e;
	    cin>>v>> e;
	    vector<int> adj[v];
	    for(int i=0; i<e; i++) {
	        int a, b;
	        cin>>a>>b;
	        adj[a].push_back(b);
            adj[b].push_back(a);
	    }
	    printAdj(adj, v);
	}
	return 0;
}