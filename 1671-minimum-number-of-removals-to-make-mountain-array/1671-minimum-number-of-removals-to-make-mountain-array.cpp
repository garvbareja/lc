class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int pi=i-1;pi>=0;pi--){
                if(nums[pi]<nums[i]) dp[i]=max(dp[i],1+dp[pi]);
            }
        }
        vector<int> pp(nums.size(),1);
        for(int i=nums.size()-1;i>=0;i--){
            for(int pi=nums.size()-1;pi>i;pi--){
                if(nums[pi]<nums[i]) pp[i]=max(pp[i],1+pp[pi]);
            }
        }
        int mxi=1;
        for(int i=0;i<dp.size();i++){
            if(dp[i]>1 && pp[i]>1) mxi=max(mxi,dp[i]+pp[i]-1);
        }
        return nums.size()-mxi;
    }
};