class Solution {
public:
    int dfs(vector<int>& nums,int index,int state,int k,vector<vector<vector<int>>>& dp){
        if(index>=nums.size()) return 0;
        if(!k) return 0;
        if(dp[index][state][k]!=-1) return dp[index][state][k];
        if(state){
            return dp[index][state][k]=max(dfs(nums,index+1,1,k,dp),-nums[index]+dfs(nums,index+1,0,k,dp));
        }else{
            return dp[index][state][k]=max(dfs(nums,index+1,0,k,dp),nums[index]+dfs(nums,index+1,1,k-1,dp));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return dfs(prices,0,1,k,dp);
    }
};