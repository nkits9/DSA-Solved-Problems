#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;


int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};
int n, m;

void floodFill(vvi &grid, int x, int y, int q, vvi &vis, int p) {
    vis[x][y] = 1;
    grid[x][y] = q;
    for(int k=0; k<4; k++) {
	    int a = x + row[k];
	    int b = y + col[k];
	    if(a>=0 && a<n && b>=0 && b<m && grid[a][b]==p && !vis[a][b]) {
	        grid[a][b] = q;
	        floodFill(grid, a, b, q, vis, p);
	    }
	}
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    cin >> n >> m;
	    vvi grid(n, vi(m));
	    vvi vis(n, vi(m));
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            cin >> grid[i][j];
	            vis[i][j] = 0;
	        }
	    }
	    int x, y, q;
	    cin >> x >> y >> q;
		int p = grid[x][y];
				
		floodFill(grid, x, y, q, vis, p);
	    
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            cout << grid[i][j] << " ";
	        }
	    }
	    cout << endl;
	}
}