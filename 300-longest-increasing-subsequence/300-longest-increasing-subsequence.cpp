class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            int ans=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]) ans=max(ans,1+dp[j]);
            }
            dp[i]=ans;
        }
        return *max_element(dp.begin(),dp.end());
    }
};