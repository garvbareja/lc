class Solution {
public:
    int dfs(vector<vector<int>>& nums,vector<vector<int>>& mc,int i,int j,vector<vector<int>>& dp){
        if(i==nums.size()-1) return nums[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int z=0;z<nums[i].size();z++){
            int temp=nums[i][j]+dfs(nums,mc,i+1,z,dp);
            temp+=mc[nums[i][j]][z];
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    
    
    int minPathCost(vector<vector<int>>& nums, vector<vector<int>>& mc) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums[0].size(),-1));
        int ans=INT_MAX;
        for(int j=0;j<nums[0].size();j++){
            ans=min(ans,dfs(nums,mc,0,j,dp));
        }
        return ans;
    }
};