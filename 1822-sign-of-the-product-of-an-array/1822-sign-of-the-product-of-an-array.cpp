class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if(!nums[i]) return 0;
            if(nums[i]<0) flag?flag=false:flag=true;
        }
        return flag?1:-1;
    }
};