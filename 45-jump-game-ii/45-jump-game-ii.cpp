class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int> dp(nums.size()-1,INT_MAX);
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==0) continue;
            if(i+nums[i]>=nums.size()-1){
                dp[i]=1;continue;
            }
            else{
                int min_jump = INT_MAX;
                for(int j=i+1;j<=i+nums[i];j++){
                    if(j>=nums.size()-1) break;
                    min_jump=min(min_jump,dp[j]);
                }
                if(min_jump!=INT_MAX) dp[i]=1+min_jump;
            }
        }
        return dp[0];
    }
};