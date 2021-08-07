class Solution {
    public:

    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>grid) {

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m));
        
        queue<pair<int, int>> q;
        
        int row[4] = {1, 0, -1, 0};
        int col[4] = {0, -1, 0, 1};
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++) {
                int x = a + row[k];
                int y = b + col[k];
                
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 0) {
                    grid[x][y] = 1; // mark it as visited
                    dist[x][y] = dist[a][b] + 1;
                    q.push({x, y});
                }
            }
        }
        
        return dist;
    }
};
