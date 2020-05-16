#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct point {
   int x, y; 
};

int isPathExist(point &src, int &n, vvi &mat) {
    queue<point> q;
    q.push(src);
    mat[src.x][src.y] = 0;  //mark visited;
    int row[4] = {0, 1, 0, -1};
    int col[4] = {1, 0, -1, 0};
    while(!q.empty()) {
        point pt = q.front();   q.pop();
        if(mat[pt.x][pt.y] == 2)    return 1;
        for(int k=0; k<4; k++) {
            int x = pt.x + row[k]; 
            int y = pt.y + col[k];
            if(x>=0 && x<n && y>=0 && y<n && mat[x][y]!=0) {
                q.push({x, y});
                if(mat[x][y] != 2)
                    mat[x][y] = 0;  //mark visited;
            }
        }
    }
    return 0;
}

int main() {
	IOS;
	int t, n;
	point src;
	cin >> t;
	while(t--) {
        cin >> n;
        vvi mat(n, vi(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> mat[i][j];
                if(mat[i][j] == 1)  
                    src = {i, j};
            }
        }
        cout << isPathExist(src, n, mat) << endl;
	}
}