class Solution {
public:
    int count=0;
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || !grid[i][j]) return;
        grid[i][j]=0; count++;
        dfs(grid,i+1,j); dfs(grid,i-1,j); dfs(grid,i,j+1); dfs(grid,i,j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                    count=0;
                    dfs(grid,i,j);
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};