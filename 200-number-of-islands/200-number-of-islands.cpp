class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]=='0') return;
        grid[i][j]='0';
        vector<int> x={-1,1,0,0};
        vector<int> y={0,0,-1,1};
        for(int z=0;z<4;z++) dfs(grid,i+x[z],j+y[z]);
    }
    
    int numIslands(vector<vector<char>>& grid){
        int islands=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};