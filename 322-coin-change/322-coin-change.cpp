class Solution {
public:
    int dfs(vector<int>& nums,int target,vector<int>& dp){
        if(!target) return 0;
        if(dp[target]!=-1) return dp[target];
        long res=INT_MAX;
        for(int i=0;i<nums.size();i++) if(nums[i]<=target) res=min(res,(long)1+dfs(nums,target-nums[i],dp));
        return dp[target]=res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int res=dfs(coins,amount,dp);
        return res==INT_MAX?-1:res;
    }
};