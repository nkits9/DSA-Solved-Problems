
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
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            if(a == X && b == Y)
                return levelCount;

            for(int k=0; k<4; k++) {
                int x = a + row[k];
                int y = b + col[k];

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

class Solution {
  public:
  
    struct Point {
        pair<int,int> pt;
        int dist;
    };

    int shortestDistance(int n, int m, vector<vector<int>> &grid, int x, int y) {
        queue<Point> q;
        
        if(grid[0][0] == 1) {
            q.push({make_pair(0,0), 0});
            grid[0][0] = 0;     // mark as visited
        }
        
        int row[] = {1, 0, -1, 0};
        int col[] = {0, -1, 0, 1};
        
        while(!q.empty()) {
            int a = q.front().pt.first;
            int b = q.front().pt.second;
            int currDist = q.front().dist;
            q.pop();
    
            if(a == x && b == y) {
                return currDist;
            }

            for(int k=0; k<4; k++) {
                int x = a + row[k];
                int y = b + col[k];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 1) {
                    q.push({make_pair(x, y), currDist+1});
                    grid[x][y] = 0;  // mark as visited
                }
            }
        }
        return -1;
    }   
};
