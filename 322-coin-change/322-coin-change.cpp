class Solution {
public:
    int dfs(vector<int>& coins,int target,int n,vector<vector<int>>& dp){
        if(!target) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        if(n==1){
            if(target%coins[0]) return dp[n][target]=INT_MAX-1;
            else return dp[n][target]=target/coins[0];
        }
        if(coins[n-1]>target) return dp[n][target]=dfs(coins,target,n-1,dp);
        else return dp[n][target]=min(1+dfs(coins,target-coins[n-1],n,dp),dfs(coins,target,n-1,dp));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=dfs(coins,amount,coins.size(),dp);
        if(ans==INT_MAX-1) return -1;
        else return ans;
    }
};