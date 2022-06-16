class Solution {
public:
    int dfs(vector<vector<int>>& nums,int i,int j,int jj,vector<vector<vector<int>>>& dp){
        if(j<0 || jj<0 || j>=nums[0].size() || jj>=nums[0].size() || i>=nums.size()) return 0;
        if(dp[i][j][jj]!=-1) return dp[i][j][jj];
        int cherries=0;
        cherries=max(cherries,dfs(nums,i+1,j-1,jj-1,dp));
        cherries=max(cherries,dfs(nums,i+1,j-1,jj,dp));
        cherries=max(cherries,dfs(nums,i+1,j-1,jj+1,dp));
        cherries=max(cherries,dfs(nums,i+1,j,jj-1,dp));
        cherries=max(cherries,dfs(nums,i+1,j,jj,dp));
        cherries=max(cherries,dfs(nums,i+1,j,jj+1,dp));
        cherries=max(cherries,dfs(nums,i+1,j+1,jj-1,dp));
        cherries=max(cherries,dfs(nums,i+1,j+1,jj,dp));
        cherries=max(cherries,dfs(nums,i+1,j+1,jj+1,dp));
        cherries+=nums[i][j]; if(j!=jj) cherries+=nums[i][jj];
        return dp[i][j][jj]=cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return dfs(grid,0,0,grid[0].size()-1,dp);
    }
};