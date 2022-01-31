class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums,int left,int right){
        if(left>right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int leftballoon=1; if(left-1>=0) leftballoon=nums[left-1];
        int rightballoon=1; if((right+1)!=nums.size()) rightballoon=nums[right+1];
        int ans=0;
        for(int i=left;i<=right;i++){
            int cur=leftballoon*nums[i]*rightballoon+dfs(nums,left,i-1)+dfs(nums,i+1,right);
            ans=max(ans,cur);
        }
        return dp[left][right]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        return dfs(nums,0,nums.size()-1);
    }
};