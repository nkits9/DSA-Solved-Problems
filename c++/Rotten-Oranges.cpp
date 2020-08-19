#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

// Approach 1: Do Level order traversal in graph and keep the count of levels,
//             which is equal to total time taken to rot oranges.
int main() {
    IOS;
    int t, n, m, x, y;
    int row[] = {0, 1, 0, -1};
    int col[] = {1, 0, -1, 0};
    cin >> t;
    while(t--) {
        int timeTaken = 0, freshOranges = 0;
        queue<pii> q;
        cin >> n >> m;
        vvi mat(n, vi(m));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> mat[i][j];
                if(mat[i][j] == 2)
                    q.push({i, j});
                if(mat[i][j] == 1)
                    freshOranges++;
            }
        }
        while(!q.empty()) {
            int nodeCount = q.size();
            while(nodeCount--) {
                pii pair = q.front();   q.pop();
                for(int k=0; k<4; k++) {
                    x = pair.first + row[k];
                    y = pair.second + col[k];
                    if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1) {
                        q.push({x, y});
                        mat[x][y] = 2;   
                        freshOranges--;             
                    }
                }
            }
            timeTaken++;
        }
        timeTaken = freshOranges==0 ? (timeTaken-1) : -1;
        cout << timeTaken << endl;
    }
    
}

/*Approach 2: Keep count of the maxtime for all oranges, 
                once all the freshOranges are finished return maxtime.  
*/          

struct Oranges {
    pii pt;
    int time;
};

int main() {
    IOS;
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int mat[n][m];
        int freshOranges = 0;
        queue<Oranges> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> mat[i][j];
                if(mat[i][j]==1)    freshOranges++;
                if(mat[i][j]==2)    q.push({{i, j}, 0});
            }
        }
        int timeTaken = 0;
        int row[] = {1, 0, -1, 0};
        int col[] = {0, -1, 0, 1};
        while(!q.empty()) {
            int a = q.front().pt.first;
            int b = q.front().pt.second;
            int time = q.front().time;
            q.pop();
      
            if(freshOranges == 0) {
                cout << timeTaken << endl;
                break;
            }
          
            for(int k=0; k<4; k++) {
                int x = a + row[k];
                int y = b + col[k];
                if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1) {
                    mat[x][y] = 2;
                    timeTaken = max(timeTaken, time+1);
                    q.push({{x, y}, time+1});
                    freshOranges--;
                }
            }
        }
        if(freshOranges != 0) {
            cout << -1 << endl;
        }
    }
}