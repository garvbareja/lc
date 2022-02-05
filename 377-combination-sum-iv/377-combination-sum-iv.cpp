class Solution {
public:
    vector<int> dp;    
    int dfs(vector<int>& nums,int sum){
        if(sum<0) return 0;
        if(!sum) return 1;
        if(dp[sum]!=-1) return dp[sum];
        int ans=0;
        for(int i=0;i<nums.size();i++) ans+=dfs(nums,sum-nums[i]);
        return dp[sum]=ans;
    }
    
    int combinationSum4(vector<int>& nums, int sum) {
        dp.resize(sum+1,-1);
        return dfs(nums,sum);
    }
};