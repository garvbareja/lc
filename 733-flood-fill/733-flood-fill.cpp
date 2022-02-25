class Solution {
public:
    int og,nc;
    void dfs(vector<vector<int>>& image,int i,int j){
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j]!=og) return;
            image[i][j]=nc;
            dfs(image,i+1,j); dfs(image,i-1,j);
            dfs(image,i,j+1); dfs(image,i,j-1);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        og=image[sr][sc]; nc=newColor;
        if(og!=nc) dfs(image,sr,sc);
        return image;
    }
};