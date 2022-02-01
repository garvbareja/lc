class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long temp=0; vector<int> ans={0,0};
        for(int i=0;i<nums.size();i++) temp^=nums[i];
        temp&=~(temp-1);
        for(int i=0;i<nums.size();i++){
            if(nums[i]&temp) ans[0]^=nums[i];
            else ans[1]^=nums[i];
        }
        return ans;
    }
};