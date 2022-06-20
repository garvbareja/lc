class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        vector<vector<int>>dp (nums.size()+1,vector<int>(2,0));
        for(int index=nums.size()-1;index>=0;index--){
            dp[index][1]=max(dp[index+1][1],-nums[index]+dp[index+1][0]);
            dp[index][0]=max(dp[index+1][0],nums[index]-fee+dp[index+1][1]);
        }
        return dp[0][1];
    }
};