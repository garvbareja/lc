class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums.back());
        int ans;
        int prev=nums.back(); int prev2=0;
        for(int i=nums.size()-2;i>=1;i--){
            int cur=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=cur;
        }
        ans=prev; prev=nums[nums.size()-2]; prev2=0;
        for(int i= nums.size()-3;i>=0;i--){
            int cur=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=cur;
        }
        return max(prev,ans);
    }
};