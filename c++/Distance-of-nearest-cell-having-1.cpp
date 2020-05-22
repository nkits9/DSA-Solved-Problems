#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main() {
	IOS;
	int t, n, m, inp, a, b, x, y;
	cin >> t;
	while(t--) {
		int row[] = {0, 1, 0, -1};
		int col[] = {1, 0, -1, 0};
		cin >> n >> m;
		vvi grid(n, vi(m));
		vvi dist(n, vi(m));
		queue<pii> q;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> inp;
				if(inp == 1) {
					grid[i][j] = 0;
					q.push({i, j});
					dist[i][j] = 0;
				} else {
					grid[i][j] = 1;
				}
			}
		}
		while(!q.empty()) {
			a = q.front().first;
			b = q.front().second;
			q.pop();
			for(int k=0; k<4; k++) {
				x = a + row[k];
				y = b + col[k];
				if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1) {
					grid[x][y] = 0; //mark as visited.
					q.push({x, y});
					dist[x][y] = dist[a][b] + 1;
				}
			}
		}

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cout << dist[i][j] << " ";
		    }
		}
		cout << endl;
	}
}