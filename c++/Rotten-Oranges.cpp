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

// Approach 2: Create a time matrix to keep count of the time in it for all oranges,
//             and return maximum time in the matrix.

int main() {
 IOS;
	int t, n, m, x, y, a, b; 
	int row[] = {0, 1, 0, -1};
    int col[] = {1, 0, -1, 0};
	cin >> t;
	while(t--) {
	    int freshOranges = 0, timeTaken = 0;
	    queue<pii> q;
        cin >> n >> m;
        vvi mat(n, vi(m));
        vvi time(n, vi(m, 0));
        
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
            pii pair = q.front();   q.pop();
            a = pair.first; b = pair.second;
            for(int k=0; k<4; k++) {
                x = a + row[k];
                y = b + col[k];
                if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1) {
                    q.push({x, y});
                    //mark as rotten.
                    mat[x][y] = 2; 
                    //keep track of time for each vertices.
                    if(time[x][y] == 0)
                        time[x][y] = time[a][b] + 1;
                    else
                        time[x][y] = min(time[x][y], time[a][b] + 1); 
                    
                    freshOranges--;
                }
            }
        }
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		timeTaken = max(timeTaken, time[i][j]);
        	}
        }
        timeTaken = freshOranges==0 ? timeTaken : -1;
        cout << timeTaken <<
	}   
}