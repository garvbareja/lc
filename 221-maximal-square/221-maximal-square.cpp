class Solution {
public:
    int maximalSquare(vector<vector<char>>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums[0].size()+1));
        int res=0;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums[0].size()-1;j>=0;j--){
                if(nums[i][j]=='1') dp[i][j]=1+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
                res=max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};