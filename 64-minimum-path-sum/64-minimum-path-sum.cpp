class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(dfs(grid,i+1,j,dp),dfs(grid,i,j+1,dp));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                if(i==grid.size()-1 && j==grid[i].size()-1) dp[i][j]=grid[i][j];
                else if(i==grid.size()-1) dp[i][j]=grid[i][j]+dp[i][j+1];
                else if(j==grid[0].size()-1) dp[i][j]=grid[i][j]+dp[i+1][j];
                else dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};