class Solution {
public:
//     int dfs(vector<int>& nums,int n,int price,vector<vector<int>>& dp){
//         if(!n) return 0;
//         if(dp[n][price+1]!=-1) return dp[n][price+1];
//         if(price>=0){
//             return dp[n][price+1]=max(dfs(nums,n-1,price,dp),price-nums[n-1]+dfs(nums,n-1,-1,dp));
//         }else{
//             return dp[n][price+1]=max(dfs(nums,n-1,-1,dp),dfs(nums,n-1,nums[n-1],dp));
//         }
//     }
    
    
//     int maxProfit(vector<int>& nums) {
//         int size=*max_element(nums.begin(),nums.end())+3;
//         vector<vector<int>> dp(nums.size()+1,vector<int>(size,-1));
//         return dfs(nums,nums.size(),-1,dp);
//     }
    int dfs(vector<int>& nums,int n,int cansell,vector<vector<int>>& dp){
        if(!n) return 0;
        if(n==1){
            if(cansell) return 0;
            else return -nums[0];
        }
        if(dp[n][cansell]!=-1) return dp[n][cansell];
        if(cansell) return dp[n][cansell]=max(dfs(nums,n-1,1,dp),nums[n-1]+dfs(nums,n-1,0,dp));
        else return dp[n][cansell]=max(dfs(nums,n-1,0,dp),dfs(nums,n-1,1,dp)-nums[n-1]);
    }
    
    
    int maxProfit(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(2,-1));
        return dfs(nums,nums.size(),1,dp);
    }
};