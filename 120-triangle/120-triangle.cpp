class Solution {
public:
    vector<vector<int>> dp;
    int help(vector<vector<int>>& nums,int i,int j){
        if(i>=nums.size() || j>=nums[i].size()) return INT_MAX/10;
        if(i==nums.size()-1) return nums[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=nums[i][j]+min(help(nums,i+1,j),help(nums,i+1,j+1));
    }
    
    int minimumTotal(vector<vector<int>>& nums){
        dp.resize(nums[nums.size()-1].size(),vector<int>(nums[nums.size()-1].size(),-1));
        return help(nums,0,0);
    }
};