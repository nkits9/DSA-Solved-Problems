void DFSUtil(int i, int j, int &N, int &M, int &noOfIsland, vector<int> *A, vector<vector<bool>> &vis) {
    int row[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int col[] = {1, 1, 0, -1, -1, -1, 0, 1};
    vis[i][j] = true;
    
    for(int k=0; k < 8; k++) {
        int x = i + row[k];
        int y = j + col[k];
        if(x < N && x >= 0 && y < M && y >= 0) {
            if(!vis[x][y] && A[i][j])
                DFSUtil(x, y, N, M, noOfIsland, A, vis);
        }
    }
}

int findIslands(vector<int> A[], int N, int M) {
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    int noOfIsland = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!vis[i][j] && A[i][j]) {
                DFSUtil(i, j, N, M, noOfIsland, A, vis);
                noOfIsland++;
            }
        }
    }
    return noOfIsland;
}