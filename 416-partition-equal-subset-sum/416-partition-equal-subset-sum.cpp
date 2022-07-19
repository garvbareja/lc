class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0; bool leave=false,take=false;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2) return false;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>((sum/2)+1,false));
        for(int n=0;n<=nums.size();n++){
            for(int target=0;target<=(sum/2);target++){
                if(!target) dp[n][target]=true;
                else if(!n) dp[n][target]=false;
                else{
                    take = false;
                    if(nums[n-1]<=target) take=dp[n-1][target-nums[n-1]];
                    leave=dp[n-1][target];
                    dp[n][target]=leave||take;
                }
            }
        }
        return dp[nums.size()][sum/2];
    }
};