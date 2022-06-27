class Solution {    
public:
    int dfs(vector<int>& nums,int i,unordered_map<int,int>& hash,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]*hash[nums[i]],skip=dfs(nums,i+1,hash,dp);
        if(i+1<nums.size() && nums[i+1]==nums[i]+1) take+=dfs(nums,i+2,hash,dp);
        else take+=dfs(nums,i+1,hash,dp);
        return dp[i]=max(take,skip);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> hash; vector<int> toprocess;
        for(int i=0;i<nums.size();i++){
            if(!hash.count(nums[i])) toprocess.push_back(nums[i]);
            hash[nums[i]]++;
        }
        sort(toprocess.begin(),toprocess.end());
        vector<int> dp(toprocess.size(),-1);
        return dfs(toprocess,0,hash,dp);
    }
};