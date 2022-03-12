class Solution {
public:
    bool isMonotonic(vector<int>& nums){
        int flag=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]) continue;
            if(!flag){
                if(nums[i-1]<nums[i]) flag=1;
                else flag=-1;
            }else{
                if(flag>0 && nums[i-1]>nums[i]) return false;
                if(flag<0 && nums[i-1]<nums[i]) return false;
            }
        }
        return true;
    }
};