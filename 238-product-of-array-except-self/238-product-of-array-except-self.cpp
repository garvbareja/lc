class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==2) return {nums[1],nums[0]};
        vector<int> left(nums.size(),1);
        for(int i=1;i<nums.size();i++) left[i]=left[i-1]*nums[i-1];
        int toright=1;
        for(int i=nums.size()-2;i>=0;i--){
            toright*=nums[i+1];
            left[i]*=toright;
        }
        return left;
    }
};