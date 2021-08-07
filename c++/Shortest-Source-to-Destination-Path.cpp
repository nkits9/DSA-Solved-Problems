
// Method 1 : 

int shortestDistance(int N, int M, vector<vector<int>> mat, int X, int Y) {
        if(mat[0][0] == 0)  return -1;
        
        int n = mat.size(), m =  mat[0].size();
        queue<pair<int, int>> q;
        q.push({0, 0});
        mat[0][0] = -1;  // mark (0,0) as visited
        
        int levelCount = 0;
        
        int row[4] = {0, 1, 0, -1};
        int col[4] = {1, 0, -1, 0};
        
        while(!q.empty()) {
            int nodeCount = q.size();
            while(nodeCount--) {
                pair<int, int> temp = q.front();
                q.pop();
                
                if(temp.first == X && temp.second == Y)
                    return levelCount;
                    
                for(int k=0; k<4; k++) {
                    int x = row[k] + temp.first;
                    int y = col[k] + temp.second;
                    
                    if(x>=0 && x<n && y>=0 && y<m && (mat[x][y]==1)) {
                        q.push({x, y});
                        mat[x][y] = -1; 
                    }
                }    
            }
            levelCount++;
        }
        
        return -1;
    }




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Method 2: 

#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mp make_pair
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;


struct Point {
    pii pt;
    int dist;
};


int minSteps(pii dest, vvi &mat, int n, int m ) {
    queue<Point> q;
    if(mat[0][0] == 1) {
        q.push({mp(0,0), 0});
    }
    int row[] = {1, 0, -1, 0};
    int col[] = {0, -1, 0, 1};
    
    while(!q.empty()) {
        int a = q.front().pt.first;
        int b = q.front().pt.second;
        int currDist = q.front().dist;

        if(dest.first == a && dest.second == b) {
            return currDist;
        }
        q.pop();

        for(int k=0; k<4; k++) {
            int x = a + row[k];
            int y = b + col[k];
            if(x>=0 && x<n && y>=0 && y<m && mat[x][y] == 1) {
                q.push({mp(x, y), currDist+1});
                mat[a][b] = 0;  //mark as visited
            }
        }
    }
    return -1;
}

int main() {
    IOS;
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vvi mat(n, vi(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) 
                cin >> mat[i][j];
        }
        pii dest;
        cin >> dest.first >> dest.second;
        cout << minSteps(dest, mat, n, m) << endl;
    }
}
