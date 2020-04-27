#include <bits/stdc++.h>
using namespace std;

int countOfPath(vector<int> adj[],bool vis[],int s,int d,int &count)
{
    vis[s]=true;
    if(s==d){
        count++;
    }
    for(int i=0; i<adj[s].size(); i++) {
        if(!vis[adj[s][i]])
            countOfPath(adj, vis, adj[s][i], d, count);
    }
    vis[s]=false;
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) {
        int v, e;
        cin>>v>>e;
        bool vis[v] = {false};
        vector<int> adj[v];
        for(int i=0; i<e; i++) {
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        int count = 0;
        int s, d;
        cin>>s>>d;
        cout<<countOfPath(adj, vis, s, d, count)<<"\n";
    }
}