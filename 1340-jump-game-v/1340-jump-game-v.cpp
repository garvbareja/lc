class Solution {
public:
    int dd;
    vector<int> dp;
    int dfs(vector<int>& nums,int i){
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        for(int z=1;z<=dd;z++)
            if(i+z<nums.size() && nums[i+z]<nums[i]) ans=max(ans,1+dfs(nums,i+z));
            else break;
        for(int z=1;z<=dd;z++)
            if(i-z>=0 && nums[i-z]<nums[i]) ans=max(ans,1+dfs(nums,i-z));
            else break;
        return dp[i]=ans;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int ans=0; dd=d;
        dp.resize(arr.size(),-1);
        for(int i=0;i<arr.size();i++) ans=max(ans,1+dfs(arr,i));
        return ans;
    }
};