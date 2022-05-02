class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int nexteven=0;
        for(int i=0;i<nums.size();i++){
            if(!(nums[i]%2)) swap(nums[nexteven++],nums[i]);
        }
        return nums;
    }
};