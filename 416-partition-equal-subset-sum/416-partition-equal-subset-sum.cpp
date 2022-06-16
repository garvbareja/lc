class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(arr.size()+1,vector<bool>(k+1,false));
    for(int i=0;i<arr.size();i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=arr.size();i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(arr[i-1]<=j) if(!dp[i][j]) dp[i][j]=dp[i-1][j-arr[i-1]];
        }
    }
    return dp.back().back();
}
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2) return false;
        return subsetSumToK(nums.size(),sum/2,nums);
    }
};