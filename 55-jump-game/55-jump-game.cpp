class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(!nums[0]) return false;
        int latest = nums.size()-1,i=latest-1;
        for(;i>0;i--) if(nums[i]+i>=latest) latest = i;
        return nums[i]+i>=latest;
    }
};
