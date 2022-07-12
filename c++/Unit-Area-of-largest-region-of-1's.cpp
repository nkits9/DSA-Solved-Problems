typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    public:   
     
    int row[8] = {0, 1, 1, 1, 0, -1, -1 , -1};
    int col[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    void DFSUtil(int x, int y, int &n, int &m, vvi &mat, int &count) {
    	mat[x][y] = 0; // Mark visited
    	count++;
    	
    	for (int k = 0; k < 8; k++) {
    		int c = x + row[k];
    		int d = y + col[k];
    		if (c >= 0 && c < n && d >= 0 && d < m && mat[c][d]) {
    			DFSUtil(c, d, n, m, mat, count);
    		}
    	}
    	
    	return;
    }
    
    
    int findMaxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int maxRegion = 0, count;
        
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j]) {
					count = 0;
					DFSUtil(i, j, n, m, mat, count);
					if (count > maxRegion)   maxRegion = count;
				}
			}
		}
		
		return maxRegion;
    }
};
