class Solution {
public:
    bool valid(int i,int high){
        if(i<=0 || i>=high) return false;
        return true;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(!valid(nums[i],nums.size()+1)) nums[i]=0;
        }
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])>0){
                if(!nums[abs(nums[i])-1]) nums[abs(nums[i])-1]=-abs(nums[i]);
                else nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) return i+1;
        }
        return nums.size()+1;
    }
};