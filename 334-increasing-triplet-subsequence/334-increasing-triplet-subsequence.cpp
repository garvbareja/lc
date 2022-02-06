class Solution {
public:
    bool increasingTriplet(vector<int>& nums){
        int i=0,first=INT_MAX,second=INT_MAX;
        while(i<nums.size()){
            if(first>=nums[i]) first = nums[i];
            else if(second>=nums[i]) second = nums[i];
            else return true;
            i++;
        }
        return false;
    }
};