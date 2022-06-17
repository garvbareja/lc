class Solution {
public:
    int dfs(vector<int>& coins,int target,int n,vector<vector<int>>& dp){
        if(!target) return 1;
        if(!n) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int take=0;
        if(coins[n-1]<=target) take=dfs(coins,target-coins[n-1],n,dp);
        int leave=dfs(coins,target,n-1,dp);
        return dp[n][target]=take+leave;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return dfs(coins,amount,coins.size(),dp);
    }
};