class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int prev2=nums[0],prev=max(nums[0],nums[1]),cur=prev;
        for(int i=2;i<nums.size();i++){
            cur=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=cur;
        }
        return cur;
    }
};