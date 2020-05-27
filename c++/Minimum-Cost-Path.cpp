#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;

struct Cell {
    int x, y, distance;
    Cell(int a, int b, int d) {
        x = a;
        y = b; 
        distance = d;
    }
};

struct CompareDistance { 
    bool operator()(Cell const& c1, Cell const& c2) { 
        return c1.distance > c2.distance; 
    } 
};

int shortest(vvi &grid, int n, int m) {
    priority_queue<Cell, vector<Cell>, CompareDistance> q;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    
    vvi vis(n, vi(m, false));
    vvi dist(n, vi(m, INT_MAX));
    dist[0][0] = grid[0][0];

    q.push(Cell(0, 0, 0));
    vis[0][0] = true; 
    
    while(!q.empty()) {
        Cell k = q.top();  
        q.pop();
        for(int i=0; i<4; i++) {
            int x = k.x + dx[i];
            int y = k.y + dy[i];
            if(x<0 || x>=n || y<0 || y>=m)  continue;
            if(dist[x][y] > dist[k.x][k.y] + grid[x][y]) {
                dist[x][y] = dist[k.x][k.y] + grid[x][y];
                if(!vis[x][y]) {
                    q.push(Cell(x, y, dist[x][y]));
                    vis[x][y] = true;
                }
            }
        }
    }
    return dist[n-1][m-1];
}

int main() {
	IOS;
	int t, n;
	cin >> t;
	while(t--) {
        cin >> n;
        vvi grid(n, vi(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> grid[i][j];
            }
        }
        cout << shortest(grid, n, n) << endl;
	}
}