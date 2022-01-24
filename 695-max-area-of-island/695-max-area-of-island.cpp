class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || !grid[i][j]) return 0;
        int ans = 0;
        vector<int> x={-1,+1,0,0};
        vector<int> y={0,0,-1,+1};
        grid[i][j]=0;
        for(int z=0;z<4;z++) ans+=dfs(grid,i+x[z],j+y[z]);
        return 1+ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};