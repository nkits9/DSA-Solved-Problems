#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;

void DFSUtil(int x, int y, int &n, int &m, vvi &mat, int &count) {
	mat[x][y] = 0; // Mark visited
	int row[] = {0, 1, 1, 1, 0, -1, -1 , -1};
	int col[] = {1, 1, 0, -1, -1, -1, 0, 1};
	for (int k = 0; k < 8; k++) {
		int c = x + row[k];
		int d = y + col[k];
		if (c >= 0 && c < n && d >= 0 && d < m && mat[c][d]) {
			count++;
			DFSUtil(c, d, n, m, mat, count);
		}
	}
	return;
}

int main() {
	IOS;
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vvi mat(n, vi(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}
		int maxRegion = 0, count;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j]) {
					count = 1;
					DFSUtil(i, j, n, m, mat, count);
					if (count > maxRegion)   maxRegion = count;
				}
			}
		}
		cout << maxRegion << endl;
	}
}