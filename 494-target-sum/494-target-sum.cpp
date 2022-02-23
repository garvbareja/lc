class Solution {
public:
    vector<vector<int>> dp; int find;
    int dfs(vector<int>& nums,int i,int sum){
        if(i==nums.size()){if(sum==find) return 1; else return 0;}
        if(dp[i][sum+(nums.size()*2000)]!=-1) return dp[i][sum+(nums.size()*2000)];
        return dp[i][sum+(nums.size()*2000)]=dfs(nums,i+1,sum+nums[i])+dfs(nums,i+1,sum-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        find=target;
        dp.resize(nums.size(),vector<int>(((nums.size()*4000)+1),-1));
        return dfs(nums,0,0);
    }
};