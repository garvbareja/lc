class Solution {
public:
    bool asteroidsDestroyed(long mass, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(mass<nums[i]) return false;
            mass+=nums[i];
        }
        return true;
    }
};