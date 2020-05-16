#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int>	pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int minSteps(int &x, int &y, int &n, int &m, vvi &mat) {
    queue<pii> q;
    if(mat[0][0] == 1) {
        q.push({0, 0});
        mat[0][0] = -1;  //Mark Visited.
    }
    int levelCount = 0;
    int row[] = {0, 1, 0, -1}, col[] = {1, 0, -1, 0};
    while(!q.empty()) {
        int nodeCount = q.size();
        while(nodeCount--) {
            int a = q.front().first, b = q.front().second; q.pop();
            if(a == x && b == y)    return levelCount;
            for(int k=0; k<3; k++) {
                int c = a + row[k], d = b + col[k];
                if(c >= 0 && c < n && d >= 0 && d < m && mat[c][d] == 1) {
                        q.push({c, d});
                        mat[c][d] = -1;  //Mark Visited.
                }
            }
        }
        levelCount++;
    }
    return -1;
}

int main() {
    IOS;
    int t, n, m, x, y;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vvi mat(n, vi(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                cin >> mat[i][j];
        }
        cin >> x >> y;
        cout << minSteps(x, y, n, m, mat) << endl;
    }
}