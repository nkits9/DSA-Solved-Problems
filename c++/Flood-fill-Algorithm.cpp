class Solution {
public:
    int row[4] = {1, 0, -1, 0};
    int col[4] = {0, -1, 0, 1};
    
    void fillColor(int x, int y, int initalColor, int newColor, vector<vector<int>> &image) {
        image[x][y] = newColor;
        
        for(int k=0; k<4; k++) {
            int a = x + row[k];
            int b = y + col[k];
            if(a>=0 && a<image.size() && b>=0 && b<image[0].size() && image[a][b]==initalColor)
                fillColor(a, b, initalColor, newColor, image);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor) {
        if(image[x][y] != newColor)
            fillColor(x, y, image[x][y], newColor, image);
        
        return image;
    }
}
