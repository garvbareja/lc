class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int it=0,i=0;
        while(i<nums.size()){
            nums[it++]=nums[i];
            if(i+1<nums.size() && nums[i]==nums[i+1]) nums[it++]=nums[i+1];
            while(i<nums.size()&&nums[it-1]==nums[i]) i++;
        }
        return it;
    }
};