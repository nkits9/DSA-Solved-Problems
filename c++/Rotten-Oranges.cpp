// Approach 1: Keep count of the maxtime for all oranges, once all the freshOranges are finished return maxtime.          

#define mp make_pair
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    public:
    
    struct Orange {
        pii pt;
        int time;
    };
    
    int orangesRotting(vvi& grid) {
        int n = grid.size(), m = grid[0].size();
        
        queue<Orange> q;
        
        int freshOranges = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2)
                    q.push({mp(i, j), 0});
                if(grid[i][j] == 1)
                    freshOranges++;
            }
        }
        
        int row[] = {1, 0, -1, 0};
        int col[] = {0, -1, 0, 1};
        
        int ans = INT_MIN;
        
        while(!q.empty()) {
            int a = q.front().pt.first;
            int b = q.front().pt.second;
            int curr_time = q.front().time;
            q.pop();
            
            ans = max(ans, curr_time);
            
            for(int k=0; k<4; k++) {
                int x = a + row[k];
                int y = b + col[k];
                
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 1) {
                    grid[x][y] = 2;
                    q.push({mp(x, y), curr_time+1});
                    freshOranges--;
                }
            }
            
        }
        
        // check if all the oranges are rotten in the end
        if(freshOranges != 0)   return -1;
        
        
        return ans;
    }
};


// Approach 2: Do Level order traversal in graph and keep the count of levels, which is equal to total time taken to rot oranges.

#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;


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
