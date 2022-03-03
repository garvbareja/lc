class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i>=grid.size() || j>=grid[i].size() || grid[i][j]) return 0;
        if(i==grid.size()-1 && j==grid[i].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=dfs(grid,i+1,j)+dfs(grid,i,j+1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(grid,0,0);
    }
};