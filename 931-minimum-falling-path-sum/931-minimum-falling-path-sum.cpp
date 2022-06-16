class Solution {
public:
    int dfs(vector<vector<int>>& nums,int i,int j,vector<vector<int>>& dp){
        if(i>=nums.size() || j>=nums[0].size()) return INT_MAX;
        if(i==nums.size()-1) return nums[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=nums[i][j]+min(min(dfs(nums,i+1,j-1,dp),dfs(nums,i+1,j,dp)),dfs(nums,i+1,j+1,dp));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int j=0;j<matrix[0].size();j++) ans=min(ans,dfs(matrix,0,j,dp));
        return ans;
    }
};