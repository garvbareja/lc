class Solution {
public:
    int dfs(vector<int>& nums,int i,int state,vector<vector<int>>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i][state]!=-1) return dp[i][state];
        if(state) return dp[i][state] = max(dfs(nums,i+1,1,dp),-nums[i]+dfs(nums,i+1,0,dp));
        else return dp[i][state] = max(dfs(nums,i+1,0,dp),nums[i]+dfs(nums,i+1,1,dp));
    }
    
    int maxProfit(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(2));
        for(int i=nums.size()-1;i>=0;i--){
            dp[i][1]=max(dp[i+1][1],-nums[i]+dp[i+1][0]);
            dp[i][0]=max(dp[i+1][0],nums[i]+dp[i+1][1]);
        }
        return dp[0][1];
    }
};