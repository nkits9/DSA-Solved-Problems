#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int minSteps(pii &src, pii &dest, int &n, vvi &mat) {
    queue<pii> q;
    q.push(src);
    mat[src.F][src.S] = 0; // Mark Visited
    int row[] = { -2, -1, 1, 2, 2, 1, -1, -2};
    int col[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dist = 0;
    while (!q.empty()) {
        int count = q.size();
        while (count--) {
            int dx = q.front().F, dy = q.front().S;
            q.pop();
            if (dx == dest.F && dy == dest.S)
                return dist;
            for (int k = 0; k < 8; k++) {
                int x = dx + row[k];
                int y = dy + col[k];
                if (x >= 0 && x < n && y >= 0 && y < n && mat[x][y]) {
                    q.push({x, y});
                    mat[x][y] = 0;
                }
            }
        }
        dist++;
    }
    return -1;
}

int main() {
    IOS;
    int t, n, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> n;
        vvi mat(n, vi(n, 1));
        cin >> a >> b;
        pii src  = {a - 1, b - 1};
        cin >> c >> d;
        pii dest = {c - 1, d - 1};
        cout << minSteps(src, dest, n, mat) << endl;
    }
}