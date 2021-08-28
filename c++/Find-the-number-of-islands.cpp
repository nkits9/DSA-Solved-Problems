class Solution
{
    public:
    int row[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int col[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    void islandTour(pair<int, int> src, vector<vector<char>>& grid, vector<vector<bool>> &vis) {
        int a = src.first, b = src.second;
        vis[a][b] = true;
        
        for(int k=0; k<8; k++) {
            int x = a + row[k];
            int y = b + col[k];
            
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()) {
                if(!vis[x][y] && grid[x][y]=='1')
                    islandTour({x, y}, grid, vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int noOfIsland = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    islandTour({i, j}, grid, vis);
                    noOfIsland++;
                }
            }
        }
        
        return noOfIsland;
    }
};
