class Solution {
public:
    vector<vector<bool>> vis;
    vector<int> x={0,0,-1,1};
    vector<int> y={1,-1,0,0};
    
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]=='0' || vis[i][j]) return;
        vis[i][j]=true;
        for(int z=0;z<4;z++) dfs(grid,i+x[z],j+y[z]);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vis.resize(grid.size(),vector<bool>(grid[0].size()));
        int island=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,i,j);
                    island++;
                }
            }
        }
        return island;
    }
};