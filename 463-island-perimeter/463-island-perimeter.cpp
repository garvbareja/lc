class Solution {
public:
    vector<vector<bool>> vis;
    int perimeter=0;
    
    bool valid(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || !grid[i][j]) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& grid,int i,int j){
        vis[i][j]=true;
        vector<int> x={-1,1,0,0};
        vector<int> y={0,0,1,-1};
        for(int z=0;z<4;z++){
            if(valid(grid,i+x[z],j+y[z])){
                if(!vis[i+x[z]][j+y[z]]) dfs(grid,i+x[z],j+y[z]);
            }
            else perimeter++;
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid){
        vis.resize(grid.size(),vector<bool> (grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                    dfs(grid,i,j);
                    return perimeter;
                }
            }
        }
        return 0;
    }
};