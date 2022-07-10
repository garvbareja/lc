class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j,int paint,int og){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return true;
        if(grid[i][j]==paint) return false;
        if(grid[i][j]!=og) return true;
        grid[i][j]=paint;
        bool flag=false;
        if(dfs(grid,i+1,j,paint,og)) flag=true;
        if(dfs(grid,i-1,j,paint,og)) flag=true;
        if(dfs(grid,i,j+1,paint,og)) flag=true;
        if(dfs(grid,i,j-1,paint,og)) flag=true;
        if(!flag) grid[i][j]=og;
        return false;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int i, int j, int paint) {
        int og=grid[i][j];
        if(og==paint) return grid;
        dfs(grid,i,j,99999,og);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==99999) grid[i][j]=paint;
        }
        return grid;
    }
};