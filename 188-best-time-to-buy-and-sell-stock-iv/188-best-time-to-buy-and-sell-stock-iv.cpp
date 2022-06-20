class Solution {
public:
    int maxProfit(int kk, vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size()+1,vector<vector<int>>(2,vector<int>(kk+1,0)));
        for(int index=nums.size()-1;index>=0;index--){
                for(int k=1;k<=kk;k++){
                    dp[index][1][k]=max(dp[index+1][1][k],-nums[index]+dp[index+1][0][k]);
                    dp[index][0][k]=max(dp[index+1][0][k],nums[index]+dp[index+1][1][k-1]);
                }
        }
        return dp[0][1][kk];
    }
};